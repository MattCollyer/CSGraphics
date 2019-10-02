#include <stdio.h>
#include "Tuple.h"
#include "Ray.h"
#include "Light.h"
#include "Material.h"
#include "Matrix.h"
#include "Object.h"
#include "Sphere.h"
#include "Canvas.h"
#include <math.h>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

Tuple::Tuple(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double Tuple::getX() const{
	return x;
}

double Tuple::getY() const{
	return y;
}

double Tuple::getZ() const{
	return z;
}

double Tuple::getW() const{
	return w;
}

bool Tuple::isPoint(){
	return w == 1.0;
}

bool Tuple::isVector(){
	return w == 0.0;
}

double Tuple::getMagnitude(){
	return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0) + pow(this->z, 2.0));
}

Tuple Tuple::normalize(){
	double mag = this->getMagnitude();
	return Tuple (this->x/mag, this->y/mag, this->z/mag, 0.0);
}

bool Tuple::operator==(const Tuple& other) const{
	double epsilon = 0.00001;
	return ((abs(this->x - other.getX()) < epsilon) && (abs(this->y - other.getY()) < epsilon) && (abs(this->z - other.getZ()) < epsilon)  && (abs(this->w - other.getW()) < epsilon));
}

Tuple Tuple::operator+(const Tuple& other) const{
	return  Tuple (this->x + other.getX(), this->y + other.getY(), this->z + other.getZ(), this->w + other.getW());
}

Tuple Tuple::operator-(const Tuple& other) const{

	return Tuple (this->x - other.getX(), this->y - other.getY(), this->z - other.getZ(), this->w - other.getW());
}

Tuple Tuple::operator-() const{
	return Tuple (-this->x, -this->y, -this->z, -this->w);
}

Tuple Tuple::operator*(const double& other) const{
	return Tuple (other * this->x, other * this->y, other * this->z, other * this->w);
}

Tuple Tuple::operator*(const Tuple& other) const{
	return Tuple(this->getX() * other.getX(), this->getY() * other.getY(), this->getZ() * other.getZ(), 0);
}

Tuple Tuple::operator/(const double& other) const{
	return Tuple (this->x / other, this->y / other, this->z / other, this->w / other);
}

//Ray Class

Ray::Ray(Tuple o, Tuple d):origin(o), direction(d){
	this->origin = o;
	this->direction = d;
}
Tuple Ray::getOrigin() const{
	return this->origin;
}

Tuple Ray::getDirection() const{
	return this->direction;
}

Tuple Ray::pointAtT(double t){
	return this->direction * t + this->origin;
}

//Object

Object::Object():material(),transform(4,4){}

Object::Object(Material m):material(m),transform(4,4){
	this->material = m;
	}
Object::Object(Matrix t):material(), transform(t){
	this->transform = t;
	}
Object::Object(Material m, Matrix t):material(m), transform(t){
	this->material = m;
	this->transform = t;
	}
Material Object::getMaterial(){
	return this->material;
}
Matrix Object::getTransform(){
	return this->transform;
}
void Object::setMaterial(Material m){
	this->material = m;
	}
void Object::setTransform(Matrix t){
	this->transform = t;
	}
std::vector<double> Object::intersectionsWith(Ray ray){}


std::vector <double>  Sphere::intersectionsWith(Ray ray){
	Tuple o = ray.getOrigin() - Point(0,0,0);
	double b = 2*dotProduct(ray.getDirection(), o);
	double c = dotProduct(o, o) - 1;
	double discriminant = pow(b, 2) - 4 * c;
	std::vector <double> tVals;
	if(discriminant < 0){
		return tVals ={};
	}
	else{
		double t1 = (-b - sqrt(discriminant))/2;
		double t2 = (-b + sqrt(discriminant))/2;
		return tVals = {t1, t2};
	}
}
Tuple Sphere::normalAtPoint(Tuple hitPoint){
	return hitPoint - Point(0, 0, 0);
}

Tuple Point(double x, double y, double z){
	return Tuple(x, y, z, 1.0);
}

Tuple Vector(double x, double y, double z){
	return Tuple(x, y, z, 0.0);
}

Tuple Color(double red, double green, double blue){
	return Tuple(red, green, blue, 0);
}

double dotProduct(Tuple a, Tuple b){
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}		

Tuple crossProduct(Tuple a, Tuple b){
	double x = a.getY() * b.getZ() - a.getZ() * b.getY();
	double y = a.getZ() * b.getX() - a.getX() * b.getZ();
	double z = a.getX() * b.getY() - a.getY() * b.getX();
	return Tuple(x, y, z, 0.0);
}

//Canvas

Canvas::Canvas(int x, int y){
	width = x;
	height = y;
	canvas = std::vector<std::vector<Tuple>>(height,  std::vector<Tuple>(width, Color(0, 0, 0)));
}

int Canvas::getWidth(){
	return width;
}

int Canvas::getHeight(){
	return height;
}

void Canvas::writePixel(int x, int y, Tuple color){
	canvas[y][x] = color;
}

Tuple Canvas::pixelAt(int x, int y){
	return canvas[y][x];
}
void Canvas::exportPpm(){
	std::ofstream file;
	file.open("CSGRAPHICS.ppm");
	file << "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
	for (int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			file << std::to_string((int)(canvas[i][j].getX() * 255)) + " " + std::to_string((int)(canvas[i][j].getY() * 255)) + " " + std::to_string((int)(canvas[i][j].getZ() * 255)) + " ";
		}
	file << "\n";
	}
file.close();
}

//Light

Light::Light(Tuple p, Tuple c):position(p), color(c){
	position = p;
	color = c;
}

Tuple Light::getPosition(){
	return position;
}

Tuple Light::getColor(){
	return color;
}

//Material
Material::Material():color(Color(1, 1, 1)){
	color = Color(1, 1, 1);
	diffuse = 1;
}

Material::Material(Tuple c, double d):color(c){
	color = c;
	diffuse = d;
}
bool Material::operator==(const Material& other) const{
	return this->color == other.getColor() && this->diffuse == other.getDiffuse();
}

Tuple Material::getColor() const{
	return color;
}

double Material::getDiffuse() const{
	return diffuse;
}

Tuple Material::colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal){
	double intensity = dotProduct(normal, unitVectorToLight);
	if(intensity < 0){
		intensity = 0;
	}
	return light.getColor() * this->color * intensity;

}
//Matrices
Matrix::Matrix(int y, int x){
	rows = y;
	columns = x;
	size = x * y;
	matrix = std::vector<std::vector<double>>(rows,  std::vector<double>(columns,0.0));
}
int Matrix::getRows() const{
	return this->rows;
}
int Matrix::getColumns() const{
	return this->columns;
}
int Matrix::getSize() const{
	return this->size;
}
double Matrix::getValue(int y, int x) const{
	return this->matrix[y][x];
}
void Matrix::setValue(int y, int x, double val){
	this->matrix[y][x] = val;
}
void Matrix::fromArray(double* arr){
	int x = 0;
	while (x < this->size){
		for (int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				this->matrix[i][j] = arr[x];
				x++;
			}
		}
	}
}	

bool Matrix::operator==(const Matrix& other) const{
	if(this->rows != other.getRows() && this->columns != other.getColumns()){
		return false;
	}
	else{
		double epsilon = 0.00001;
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				if(abs(this->matrix[i][j] - other.getValue(i, j)) > epsilon){
					return false;
				}
			}
		}
	}	
	return true;
}
bool Matrix::operator!=(const Matrix& other) const{
	return !(*this == other);
}
Matrix Matrix::operator*(const Matrix& other) const{
	Matrix returnMatrix(this->rows, this->columns);
	if(this->size != 16 && other.getSize() != 16){
		std::runtime_error("Can't multiply these matrices together");
	}
	else{
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				returnMatrix.setValue(i, j, (this->matrix[i][0] * other.getValue(0, j)) + (this->matrix[i][1] * other.getValue(1, j)) + (this->matrix[i][2] * other.getValue(2, j)) + (this->matrix[i][3] * other.getValue(3, j)));
			}
		}
	}
	return returnMatrix;
}
Tuple Matrix::operator*(const Tuple& other) const{
	double tupleArr[4] = {other.getX(), other.getY(), other.getZ(), other.getW()};
	double returnArr[4] = {0,0,0,0};
	for(int i = 0; i < this->rows; i++){
		for(int j = 0; j < this->columns; j++){
			returnArr[i] += this->matrix[i][j] * tupleArr[j];
		}	
	}
	Tuple returnTuple(returnArr[0], returnArr[1], returnArr[2], returnArr[3]);
	return returnTuple;
}
Matrix Matrix::identity(int dimmension){
	Matrix identity(dimmension, dimmension);
	for(int i = 0; i < dimmension; i++){
		identity.setValue(i, i, 1);
	}
	return identity;
}
double Matrix::determinant(){
	double determinant = 0;
	if (this->size == 4){
		determinant = this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
	}
	else{
		for(int j = 0; j < this->columns; j++){
			determinant += this->matrix[0][j] * this->cofactor(0, j);
		}
		
	}
	return determinant;
	
}
Matrix Matrix::submatrix(int row, int column){
	//input is zero based
	Matrix returnMatrix (this->rows - 1, this->columns - 1);
	int outsideCounter = 0;
	for(int i = 0; i < this->rows; i++){
		if(i != row){
			int insideCounter = 0;
			for(int j = 0; j < this->columns; j++){
				if(j != column){
					returnMatrix.setValue(outsideCounter, insideCounter, this->matrix[i][j]);
					insideCounter++;
				}
			}
			outsideCounter++;
		}
	}	
	return returnMatrix;
}
double Matrix::minor(int row, int column){
	return this->submatrix(row, column).determinant();

}
double Matrix::cofactor(int row, int column){
	double minor = this->minor(row, column);
	if(row + column % 2 == 0){
		return minor;
	}
	else{
		return -minor;
	}
}	
bool Matrix::isInvertible(){
	return this->determinant();
}
Matrix Matrix::inverse(){
	Matrix returnMatrix(this->rows, this->columns);
	if(!isInvertible()){
		std::runtime_error("Matrix not invertible");
	}
	else{	
		double determinant = this->determinant();
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				double cofactor = this->cofactor(i, j);
				returnMatrix.setValue(j, i, cofactor / determinant);
			}
		}
	}
	return returnMatrix;
}


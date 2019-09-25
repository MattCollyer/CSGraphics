#include <stdio.h>
#include "Tuple.h"
#include "Ray.h"
#include "Light.h"
#include "Material.h"
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
	
	//Sphere
	Sphere::Sphere(Material m){
		material = m;
        }
	Material Sphere::getMaterial(){
		return material;
	}

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
	
	Tuple Material::getColor(){
		return color;
	}
	
	double Material::getDiffuse(){
		return diffuse;
	}

	Tuple Material::colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal){
		double intensity = dotProduct(normal, unitVectorToLight);
		return light.getColor() * this->color * intensity;

	}

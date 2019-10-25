#include <stdio.h>
#include <math.h>
#include "Tuple.h"


Tuple::Tuple(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double Tuple::getX() const{
	return this->x;
}

double Tuple::getY() const{
	return this->y;
}

double Tuple::getZ() const{
	return this->z;
}

double Tuple::getW() const{
	return this->w;
}

bool Tuple::isPoint(){
	return this->w == 1.0;
}

bool Tuple::isVector(){
	return this->w == 0.0;
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


Tuple Tuple::Point(double x, double y, double z){
	return Tuple(x, y, z, 1.0);
}

Tuple Tuple::Vector(double x, double y, double z){
	return Tuple(x, y, z, 0.0);
}

Tuple Tuple::Color(double red, double green, double blue){
	return Tuple(red, green, blue, 0);
}

double Tuple::dotProduct(Tuple a, Tuple b){
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

Tuple Tuple::crossProduct(Tuple a, Tuple b){
	double x = a.getY() * b.getZ() - a.getZ() * b.getY();
	double y = a.getZ() * b.getX() - a.getX() * b.getZ();
	double z = a.getX() * b.getY() - a.getY() * b.getX();
	return Tuple(x, y, z, 0.0);
}

Tuple Tuple::reflect(Tuple vector, Tuple normal){
	return vector - normal * 2 * Tuple::dotProduct(vector, normal);
}

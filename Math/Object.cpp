#include "Object.h"
#include <math.h>
Object::Object():material(),transform(Matrix::identity(4)){}

Object::Object(Material m):material(m),transform(Matrix::identity(4)){
		this->material = m;
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

Tuple Object::normalAt(Tuple hitPoint){
	return Tuple(0,0,0,0); //nothing
};

std::vector<Intersection> Object::intersectionsWith(Ray ray){
		return std::vector<Intersection>();
}

void Object::translate(double x, double y, double z){
		Matrix translationMatrix = Matrix::translation(x, y, z);
		this->transform = this->transform * translationMatrix;
}

void Object::scale(double x, double y, double z){
		Matrix scalingMatrix = Matrix::scaling(x, y, z);
		this->transform = this->transform * scalingMatrix;
}

void Object::rotateX(double radians){
	Matrix rotationMatrix = Matrix::identity(4);
	rotationMatrix.setValue(1, 1, cos(radians));
	rotationMatrix.setValue(1, 2, -sin(radians));
	rotationMatrix.setValue(2, 1, sin(radians));
	rotationMatrix.setValue(2, 2, cos(radians));
	this->transform = this->transform * rotationMatrix;
}
void Object::rotateY(double radians){
	Matrix rotationMatrix = Matrix::identity(4);
	rotationMatrix.setValue(0, 0, cos(radians));
	rotationMatrix.setValue(0, 2, sin(radians));
	rotationMatrix.setValue(2, 0, -sin(radians));
	rotationMatrix.setValue(2, 2, cos(radians));
	this->transform = this->transform * rotationMatrix;
}
void Object::rotateZ(double radians){
	Matrix rotationMatrix = Matrix::identity(4);
	rotationMatrix.setValue(0, 0, cos(radians));
	rotationMatrix.setValue(0, 1, -sin(radians));
	rotationMatrix.setValue(1, 0, sin(radians));
	rotationMatrix.setValue(1, 1, cos(radians));
	this->transform = this->transform * rotationMatrix;
}

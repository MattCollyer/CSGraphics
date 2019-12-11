#include "Triangle.h"
#include <stdio.h>

Triangle::Triangle(Tuple a, Tuple b, Tuple c): Object(), a(a), b(b), c(c){}


std::vector <double>  Triangle::intersectionsWith(Ray ray){
	//Yeah this looks bad but its way more readable. Overall better I think.
	Ray worldRay = ray.transform(this->getTransform().inverse());
	double ax = this->a.getX();
	double ay = this->a.getY();
	double az = this->a.getZ();
	double bx = this->b.getX();
	double by = this->b.getY();
	double bz = this->b.getZ();
	double cx = this->c.getX();
	double cy = this->c.getY();
	double cz = this->c.getZ();
	double ox = worldRay.getOrigin().getX();
	double oy = worldRay.getOrigin().getY();
	double oz = worldRay.getOrigin().getZ();
	double dx = worldRay.getDirection().getX();
	double dy = worldRay.getDirection().getY();
	double dz = worldRay.getDirection().getZ();
	Matrix numerator = Matrix(3, 3);
	Matrix denomenator = Matrix(3, 3);
	//CRAMER’S RULE
	std::vector <double> intersection;
	double denomenatorArr[9] = {ax - bx, ax - cx, dx,
								ay - by, ay - cy, dy,
								az - bz, az - cz, dz};
	denomenator.fromArray(denomenatorArr);
	double denomenatorDet = denomenator.determinant();
	if(denomenatorDet == 0){
		return intersection;
	}
	double numeratorBeta[9] = {ax - ox, ax - cx, dx,
						 	  ay - oy, ay - cy, dy,
						 	  az - oz, az - cz, dz};
	numerator.fromArray(numeratorBeta);
	double beta = numerator.determinant() / denomenatorDet;

	double numeratorGamma[9] = {ax - bx, ax - ox, dx,
							 ay - by, ay - oy, dy,
							 az - bz, az - oz, dz};
	numerator.fromArray(numeratorGamma);
	double gamma = numerator.determinant() / denomenatorDet;
	double numeratorT[9] = {ax - bx, ax - cx, ax - ox,
							ay - by, ay - cy, ay - oy,
					 		az - bz, az - cz, az - oz};
	numerator.fromArray(numeratorT);
	double t = numerator.determinant() / denomenatorDet;
	if(beta >= 0 && gamma >= 0 && beta + gamma <= 1){
		intersection.push_back(t);
	}
	return intersection;
}

Tuple Triangle::normalAt(Tuple point){
	return this->transform.inverse().transpose() * Tuple::crossProduct(this->b - this->a, this->c - this->a);
}

#include "Triangle.h"
#include <stdio.h>

std::vector <Intersection>  Triangle::intersectionsWith(Ray ray){
	//Yeah this looks bad but its way more readable. Overall better I think.
	double ax = this->a.getX();
	double ay = this->a.getY();
	double az = this->a.getZ();
	double bx = this->b.getX();
	double by = this->b.getY();
	double bz = this->b.getZ();
	double cx = this->c.getX();
	double cy = this->c.getY();
	double cz = this->c.getZ();
	double ox = ray.getOrigin().getX();
	double oy = ray.getOrigin().getY();
	double oz = ray.getOrigin().getZ();
	double dx = ray.getDirection().getX();
	double dy = ray.getDirection().getY();
	double dz = ray.getDirection().getZ();
	Matrix numerator = Matrix(3, 3);
	Matrix denomenator = Matrix(3, 3);

	//CRAMER’S RULE
	double numeratorBeta[9] = {ax - ox, ax - cx, dx,
						 	  ay - oy, ay - cy, dy,
						 	  az - oz, az - cz, dz};
	numerator.fromArray(numeratorBeta);

	double denomenatorArr[9] = {ax - bx, ax - cx, dx,
								ay - by, ay - cy, dy,
								az - bz, az - cz, dz};
	denomenator.fromArray(denomenatorArr);
	if(denomenator.isInvertible()){
		double beta = numerator.determinant() / denomenator.determinant();
		double numeratorGamma[9] = {ax - bx, ax - ox, dx,
							 ay - by, ay - oy, dy,
							 az - bz, az - oz, dz};
		numerator.fromArray(numeratorGamma);
		double gamma = numerator.determinant() / denomenator.determinant();
		double numeratorT[9] = {ax - bx, ax - cx, ax - ox,
								ay - by, ay - cy, ay - oy,
						 		az - bz, az - cz, az - oz};
		numerator.fromArray(numeratorT);
		double t = numerator.determinant() / denomenator.determinant();

		if(beta >= 0 && gamma >= 0 && beta + gamma <= 1){
			Intersection intersect = Intersection(t, ray, this);
			return {intersect};
		}
		else{
			return {}; //empty vector
		}
	}
	else{
		return {}; //empty vector
	}
}

Tuple Triangle::normalAt(Tuple point){
	return Tuple::crossProduct(this->b - this->a, this->c - this->a);
}

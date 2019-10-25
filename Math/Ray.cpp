#include <stdio.h>
#include <math.h>
#include "Ray.h"



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

Ray Ray::transform(Matrix m){
	Ray returnRay(m * this->origin, m * this->direction);
	return returnRay;
}

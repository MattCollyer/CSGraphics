#include "Plane.h"
#include <math.h>




std::vector <Intersection> Plane::intersectionsWith(Ray ray){
	double epsilon = 0.00001;
	if(abs(ray.getDirection().getY()) < epsilon){
		return {};
	}
	else{
		double t = -ray.getOrigin().getY() / ray.getDirection().getY();
		Intersection intersection (t, ray, *this);
		return {intersection};
	}
}
Tuple normalAt(Tuple hitPoint){
	return Tuple::Vector(0, 1, 0);
}

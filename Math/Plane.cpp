#include "Plane.h"
#include <math.h>




std::vector <Intersection> Plane::intersectionsWith(Ray ray){
	ray = ray.transform(this->getTransform().inverse());
	double epsilon = 0.00001;
	if(abs(ray.getDirection().getY()) < epsilon){
		return {};
	}
	else{
		double t = -ray.getOrigin().getY() / ray.getDirection().getY();
		Intersection intersection (t, ray, this);
		return {intersection};
	}
}
Tuple Plane::normalAt(Tuple hitPoint){
	Tuple objNormal = Tuple::Vector(0, 1, 0);
	Tuple worldNormal = this->transform.inverse().transpose() * objNormal;
	worldNormal.setW(0);
	return worldNormal.normalize();
}

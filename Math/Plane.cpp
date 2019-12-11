#include "Plane.h"
#include <math.h>




std::vector <double> Plane::intersectionsWith(Ray ray){
	Ray worldRay = ray.transform(this->getTransform().inverse());
	double epsilon = 0.00001;
	if(abs(worldRay.getDirection().getY()) < epsilon){
		return {};
	}
	else{
		double t = -worldRay.getOrigin().getY() / worldRay.getDirection().getY();
		return {t};
	}
}
Tuple Plane::normalAt(Tuple hitPoint){
	Tuple objNormal = Tuple::Vector(0, 1, 0);
	Tuple worldNormal = this->transform.inverse().transpose() * objNormal;
	worldNormal.setW(0);
	return worldNormal.normalize();
}

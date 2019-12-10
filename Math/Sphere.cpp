#include "Sphere.h"

std::vector <double>  Sphere::intersectionsWith(Ray ray){
	ray = ray.transform(this->getTransform().inverse());
	Tuple o = ray.getOrigin() - Tuple::Point(0,0,0);
	double a = Tuple::dotProduct(ray.getDirection(), ray.getDirection());
	double b = 2 * Tuple::dotProduct(ray.getDirection(), o);
	double c = Tuple::dotProduct(o, o) - 1;
	double discriminant = pow(b, 2) - 4 * a * c;
	if(discriminant < 0){
		return {};
	}
	else{
		double t1 = (-b - sqrt(discriminant))/(2 * a);
		double t2 = (-b + sqrt(discriminant))/(2 * a);
		return {t1, t2};
	}
}

Tuple Sphere::normalAt(Tuple hitPoint){
	Tuple objectPoint = this->transform.inverse() * hitPoint;
	Tuple objectNormal = hitPoint - Tuple::Point(0, 0, 0);
	Tuple worldNormal = this->transform.inverse().transpose() * objectNormal;
	worldNormal.setW(0.0);
	return worldNormal.normalize();
}

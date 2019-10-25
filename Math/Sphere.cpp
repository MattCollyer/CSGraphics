#include "Sphere.h"

std::vector <Intersection>  Sphere::intersectionsWith(Ray ray){
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
		Intersection intersection1(t1, ray, *this);
		Intersection intersection2(t2, ray, *this);

		return {intersection1, intersection2};
	}
}

Tuple Sphere::normalAtPoint(Tuple hitPoint){
	return hitPoint - Tuple::Point(0, 0, 0);
}
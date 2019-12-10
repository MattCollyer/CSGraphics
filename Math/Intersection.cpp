#include "Intersection.h"
#include "Object.h"

Intersection::Intersection(double T, Ray r, std::shared_ptr<Object> o):
	t(T),
	ray(r),
	object(o){}

double Intersection::getT() const{
		return t;
}
std::shared_ptr<Object> Intersection::getObjectPtr(){
	return object;
}

HitRecord Intersection::generateHitRecord(){
		double epsilon = 0.00001;
		Tuple hitPoint = ray.pointAtT(t);
		Tuple normal = object->normalAt(hitPoint);
		Tuple eye = (ray.getOrigin() - hitPoint).normalize();
		bool isInside = false;
		if(Tuple::dotProduct(normal, eye) < 0){
				isInside = true;
				normal = -normal;
		}
		Tuple overPoint = hitPoint + (normal * epsilon);
		Tuple reflectV = Tuple::reflect(ray.getDirection(), normal);
		return HitRecord(this->object, hitPoint, normal, eye, isInside, overPoint, reflectV);
}
bool Intersection::operator<(const Intersection& other) const{
	if(this->t < other.getT()){
		return true;
	}
	else{
		return false;
	}
}

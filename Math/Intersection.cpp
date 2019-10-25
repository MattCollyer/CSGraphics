#include "Intersection.h"
#include "Object.h"

Intersection::Intersection(double t, Ray r, Object o): ray(r){
		this->t = t;
		this->ray = r;
		this->object = &o;

}
double Intersection::getT(){
		return this->t;
}

HitRecord Intersection::generateHitRecord(){
		double epsilon = 0.00001;
		Tuple hitPoint = this->ray.pointAtT(this->t);
		Tuple normal = this->object->normalAtPoint(hitPoint);
		Tuple eye = (this->ray.getOrigin() - hitPoint).normalize();
		bool isInside = false;
		if(Tuple::dotProduct(normal, eye) < 0){
				isInside = true;
				normal = -normal;
		}
		Tuple overPoint = hitPoint + (normal * epsilon);
		return HitRecord(hitPoint, normal, eye, isInside, overPoint);
}
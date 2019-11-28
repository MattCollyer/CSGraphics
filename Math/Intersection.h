#ifndef Intersection_H
#define Intersection_H
#include "Tuple.h"
#include "Ray.h"
#include "HitRecord.h"

class Object;
class Intersection{
	private:
		double t;
		Ray ray;
		Object *object;

	public:
		Intersection(double t, Ray ray, Object * o);
		double getT() const;
		Object* getObjectPtr();
		HitRecord generateHitRecord();
		bool operator<(const Intersection& other) const;
};


#endif

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
		std::shared_ptr<Object> object;

	public:
		Intersection(double t, Ray ray, std::shared_ptr<Object>  o);
		double getT() const;
		std::shared_ptr<Object> getObjectPtr();
		HitRecord generateHitRecord();
		bool operator<(const Intersection& other) const;
};


#endif

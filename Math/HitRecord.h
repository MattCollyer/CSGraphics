#ifndef HitRecord_H
#define HitRecord_H
#include "Tuple.h"

class Object;
class HitRecord{

	public:
		Object* object;
		Tuple hitPoint;
		Tuple normal;
		Tuple eye;
		bool isInside;
		Tuple overPoint;
		HitRecord(Object* object, Tuple hitPoint, Tuple normal, Tuple eye, bool isInside, Tuple overPoint);

};

#endif

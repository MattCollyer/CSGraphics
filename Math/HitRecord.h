#ifndef HitRecord_H
#define HitRecord_H
#include "Tuple.h"
class HitRecord{

	public:
		Tuple hitPoint;
		Tuple normal;
		Tuple eye;
		bool isInside;
		Tuple overPoint;
		HitRecord(Tuple hitPoint, Tuple normal, Tuple eye, bool isInside, Tuple overPoint);

};

#endif

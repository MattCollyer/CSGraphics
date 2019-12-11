#ifndef HitRecord_H
#define HitRecord_H
#include "Tuple.h"

class Object;
class HitRecord{

	public:
		std::shared_ptr<Object> object;
		Tuple hitPoint;
		Tuple normal;
		Tuple eye;
		bool isInside;
		Tuple overPoint;
		Tuple reflectV;
		HitRecord(std::shared_ptr<Object> object, Tuple hitPoint, Tuple normal, Tuple eye, bool isInside, Tuple overPoint, Tuple reflectV);

};
std::ostream& operator << ( std::ostream& os, HitRecord const& obj );


#endif

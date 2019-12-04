#include "HitRecord.h"

HitRecord::HitRecord(Object* o, Tuple hit, Tuple norm, Tuple eyeVector, bool inside, Tuple over) :
	object(o),
	hitPoint(hit),
	normal(norm),
	eye(eyeVector),
	isInside(inside),
	overPoint(over) {}

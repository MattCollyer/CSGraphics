#include "HitRecord.h"

HitRecord::HitRecord(Tuple hit, Tuple norm, Tuple eyeVector, bool inside, Tuple over) :
	hitPoint(hit),
	normal(norm),
	eye(eyeVector),
	isInside(inside),
	overPoint(over) {}

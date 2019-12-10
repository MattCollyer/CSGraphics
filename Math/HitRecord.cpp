#include "HitRecord.h"

HitRecord::HitRecord(std::shared_ptr<Object> o, Tuple hit, Tuple norm, Tuple eyeVector, bool inside, Tuple over, Tuple reflect) :
	object(o),
	hitPoint(hit),
	normal(norm),
	eye(eyeVector),
	isInside(inside),
	overPoint(over),
	reflectV(reflect) {}

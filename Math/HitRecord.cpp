#include "HitRecord.h"

HitRecord::HitRecord(std::shared_ptr<Object> o, Tuple hit, Tuple norm, Tuple eyeVector, bool inside, Tuple over, Tuple reflect) :
	object(o),
	hitPoint(hit),
	normal(norm),
	eye(eyeVector),
	isInside(inside),
	overPoint(over),
	reflectV(reflect) {}


std::ostream& operator << ( std::ostream& os, HitRecord const& obj ){
	os<< "HitPoint:" << obj.hitPoint << "\n";
	os<< "Normal" << obj.normal << "\n";
	os<< "Eye:" << obj.eye << "\n";
	os<< "IsInside" << obj.isInside << "\n";
	os<< "overPoint:" << obj.overPoint << "\n";
	os<< "reflectV:" << obj.reflectV << "\n";

	return os;

}

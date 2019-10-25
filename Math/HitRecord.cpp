#include "HitRecord.h"

HitRecord::HitRecord(Tuple hit, Tuple norm, Tuple eyeVector, bool inside, Tuple over):hitPoint(hit), normal(norm), eye(eyeVector), overPoint(over) {
	this->hitPoint = hit;
	this->normal = norm;
	this->eye = eyeVector;
	this->isInside = isInside;
	this->overPoint = over;
}

#ifndef Sphere_H
#define Sphere_H
#include "Object.h"
#include <vector>
#include "Intersection.h"
class Sphere: public Object{
	public:
		using Object::Object;
		std::vector <Intersection> intersectionsWith(Ray ray);
		Tuple normalAt(Tuple hitPoint);
};

#endif

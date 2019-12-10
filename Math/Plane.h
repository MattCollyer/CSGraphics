#ifndef Plane_H
#define Plane_H
#include "Object.h"

class Plane: public Object{
	public:
		using Object::Object;
		std::vector <double> intersectionsWith(Ray ray);
		Tuple normalAt(Tuple hitPoint);


};


#endif

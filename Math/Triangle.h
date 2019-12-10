#ifndef Triangle_H
#define Triangle_H
#include "Object.h"
#include "Tuple.h"

class Triangle: public Object{
	public:
			Tuple a;
			Tuple b;
			Tuple c;

			Triangle(Tuple a, Tuple b, Tuple c);
			std::vector <double> intersectionsWith(Ray ray);
			Tuple normalAt(Tuple point);

};


#endif

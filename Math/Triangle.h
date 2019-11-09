#ifndef Triangle_H
#define Triangle_H
#include "Object.h"
#include "Tuple.h"

class Triangle: public Object{
		private:
			Tuple a;
			Tuple b;
			Tuple c;
		public:
			using Object::Object;
			std::vector <Intersection> intersectionsWith(Ray ray);
			Tuple normalAt(Tuple point);

};


#endif

#ifndef Triangle_H
#define Triangle_H
#include Object
#include Tuple

class Triangle: public Object{
		private:
			Tuple a;
			Tuple b;
			Tuple c;
		public:
			using Object::Object;
			intersectionsWith(Ray ray);
			normalAtPoint(Tuple point);

};


#endif

#ifndef Sphere_H
#define Sphere_H
#include <vector>
class Sphere: public Object{
	public:
		using Object::Object;
        	std::vector <double> intersectionsWith(Ray ray);
		Tuple normalAtPoint(Tuple hitPoint);
};

#endif              

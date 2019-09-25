#ifndef Sphere_H
#define Sphere_H
#include <vector>
class Sphere{
	private:
		Material material;
	public:
		Sphere(Material m);
		Material getMaterial();
        	std::vector <double> intersectionsWith(Ray ray);
		Tuple normalAtPoint(Tuple hitPoint);
};

#endif              

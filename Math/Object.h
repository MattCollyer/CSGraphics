#ifndef Object_H
#define Object_H
#include <stdio.h>
#include "Material.h"
#include "Matrix.h"
#include "Tuple.h"
#include "Ray.h"
#include "Intersection.h"

class Object{
	private:
		Material material;
		Matrix transform;

	public:
		Object();
		Object(Material m);
		void setMaterial(Material m);
		Material getMaterial();
		void setTransform(Matrix t);
		Matrix getTransform();
		void scale(double x, double y, double z);
		void translate(double x, double y, double z);
		virtual Tuple normalAtPoint(Tuple hitPoint);
		virtual std::vector <Intersection> intersectionsWith(Ray ray);



};
#endif

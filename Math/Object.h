#ifndef Object_H
#define Object_H
#include <stdio.h>
#include "Material.h"
#include "Matrix.h"
#include "Tuple.h"
#include "Ray.h"
#include "Intersection.h"

class Object : public std::enable_shared_from_this<Object>{
	public:

		Material material;
		Matrix transform;

		Object();
		Object(Material m);
		void setMaterial(Material m);
		Material getMaterial();
		void setTransform(Matrix t);
		Matrix getTransform();
		void scale(double x, double y, double z);
		void translate(double x, double y, double z);
		void rotateX(double degrees);
		void rotateY(double degrees);
		void rotateZ(double degrees);
		virtual Tuple normalAt(Tuple hitPoint);
		virtual std::vector <double> intersectionsWith(Ray ray);

};
#endif

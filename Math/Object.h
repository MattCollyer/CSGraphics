#ifndef Object_H
#define Object_H

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
		virtual std::vector <double> intersectionsWith(Ray ray);



};
#endif

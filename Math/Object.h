#ifndef Object_H
#define Object_H

class Object{
	private:
		Material material;
		Matrix transform;

	public:
		Object();
		Object(Material m);
		Object(Matrix t);
		Object(Material m, Matrix t);
		void setMaterial(Material m);
		Material getMaterial();
		void setTransform(Matrix t);
		Matrix getTransform();
		void scale();	
		void translate();
		virtual std::vector <double> intersectionsWith(Ray ray);



};
#endif

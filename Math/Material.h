#ifndef Material_H
#define Material_H
#include "Tuple.h"
#include "Light.h"
#include "HitRecord.h"
class Material{
	private:
		Tuple color;
		double diffuse;
		double ambient;
		double specular;
		double shininess;
		double reflectivity;
		double indexOfRefraction;
		double transparency;
	public:
		//work in progress
		Material();
		Material(Tuple c, double d);
		Tuple getColor() const;
		void Material::setColor(Tuple c);
		double getDiffuse() const;
		void setDiffuse(double d);
		double getSpecular();
		void setSpecular(double s);
		Tuple colorAtPoint(HitRecord hitRecord);
		bool operator==(const Material& other) const;

};

#endif

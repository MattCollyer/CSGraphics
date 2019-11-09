#ifndef Material_H
#define Material_H
#include "Tuple.h"
#include "Light.h"
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
		double getDiffuse() const;
		Tuple colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal);
		bool operator==(const Material& other) const;

};

#endif

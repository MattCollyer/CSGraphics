#ifndef Material_H
#define Material_H
#include "Tuple.h"
#include "Light.h"
#include "HitRecord.h"

class Material{
public:
		Tuple color;
		double diffuse;
		double ambient;
		double specular;
		double shininess;
		double reflectivity;
		double indexOfRefraction;
		double transparency;

		Material();
		Material(Tuple c, double d);
		Tuple getColor() const;
		Tuple colorAtPoint(HitRecord hitRecord, std::vector <Light *> lights);
		bool operator==(const Material& other) const;

};

#endif

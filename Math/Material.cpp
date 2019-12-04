#include "Material.h"
#include <cmath>
#include <vector>

Material::Material():color(Tuple::Color(1, 1, 1)){
	diffuse = 0.9;
	ambient = 0.1;
	specular = 0;
	shininess = 200;
	reflectivity = 0;
	indexOfRefraction = 0;
	transparency = 0;
}

Material::Material(Tuple c, double d):color(c){
	diffuse = d;
}
bool Material::operator==(const Material& other) const{
	return this->color == other.color && this->diffuse == other.diffuse;
}


Tuple Material::colorAtPoint(HitRecord hitRecord, Light light, bool isShadowed){
	Tuple intensity = light.getColor();
	Tuple ambientColor = this->color * intensity * this->ambient;
	if(isShadowed){
		return ambientColor;
	}
	Tuple vectorToLight = (light.getPosition() - hitRecord.hitPoint).normalize();
	double specularIntensity = Tuple::dotProduct(hitRecord.eye, Tuple::reflect(vectorToLight, hitRecord.normal));
	if (specularIntensity < 0){
		specularIntensity = 0;
	}
	Tuple specularColor = intensity * (std::pow(specularIntensity, this->shininess) * this->specular);
	double lightDotNormal = Tuple::dotProduct(vectorToLight, hitRecord.normal);
	Tuple diffuseColor = this->color * intensity * this->diffuse * lightDotNormal;
	if (lightDotNormal < 0){
		diffuseColor = Tuple::Color(0, 0, 0);
	}
	return specularColor + diffuseColor + ambientColor;
}

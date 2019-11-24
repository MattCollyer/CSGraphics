#include "Material.h"
#include <cmath>
#include <vector>
Material::Material():color(Tuple::Color(1, 1, 1)){
	diffuse = 1;
}

Material::Material(Tuple c, double d):color(c){
	diffuse = d;
}
bool Material::operator==(const Material& other) const{
	return this->color == other.color && this->diffuse == other.diffuse;
}


Tuple Material::colorAtPoint(HitRecord hitRecord, std::vector <Light *> lights){
	Tuple finalColor = Tuple::Color(0, 0, 0);
	for(int i = 0; i < lights.size(); i++){
		Tuple intensity = lights[i]->getColor();
		Tuple vectorToLight = (lights[i]->getPosition() - hitRecord.hitPoint).normalize();
		double specularIntensity = Tuple::dotProduct(hitRecord.eye, Tuple::reflect(vectorToLight, hitRecord.normal));
		if (specularIntensity < 0){
			specularIntensity = 0;
		}
		Tuple specularColor = intensity * (std::pow(specularIntensity, this->shininess) * this->specular);
		double lightDotNormal = Tuple::dotProduct(vectorToLight, hitRecord.normal);
		Tuple diffuseColor = this->color * intensity * this->diffuse * lightDotNormal;
		if (lightDotNormal < 0){
			diffuseColor = Tuple::Color(0, 0, 0);
			specularColor = Tuple::Color(0, 0, 0);
		}
		Tuple ambientColor = this->color * intensity * this->ambient;
		finalColor = finalColor + specularColor + diffuseColor + ambientColor;
	}
	return finalColor;
}

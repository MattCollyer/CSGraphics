#include "Material.h"
#include <cmath>

Material::Material():color(Tuple::Color(1, 1, 1)){
	diffuse = 1;
}

Material::Material(Tuple c, double d):color(c){
	diffuse = d;
}
bool Material::operator==(const Material& other) const{
	return this->color == other.getColor() && this->diffuse == other.getDiffuse();
}

Tuple Material::getColor() const{
	return this->color;
}
void Material::setColor(Tuple c){
	this->color = c;
}

double Material::getDiffuse() const{
	return this->diffuse;
}
void Material::setDiffuse(double d){
	this->diffuse = d;
}
double getSpecular(){
	return this->specular;
}

void setSpecular(double s){
	this->specular = s;
}

//work in progress
Tuple Material::colorAtPoint(HitRecord hitRecord, World world){
	std::vector <Light> lights = world.getLights()
	Tuple finalColor = Tuple::Color(0, 0, 0);
	for(int i = 0; i < lights.size(); i++){
		Tuple intensity = lights[i].getColor();
		Tuple vectorToLight = (lights[i].getPosition() - hitRecord.hitPoint).normalize();
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
		finalColor += specularColor + diffuseColor + ambientColor;
	}
	return finalColor;
}

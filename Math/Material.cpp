#include "Material.h"

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
	return color;
}

double Material::getDiffuse() const{
	return diffuse;
}

//work in progress
Tuple Material::colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal){
	Tuple lightColor = light.getColor();
	double intensity = Tuple::dotProduct(normal, unitVectorToLight);
	double specularIntensity = Tuple::dotProduct(//eye, reflectedVectorToLight)
	double specular = lightColor * specularIntensity;
	Ray reflectedRay = Ray(//overPoint, eye reflected over normal)
	if(intensity < 0){
		intensity = 0;
	}
	return lightColor * this->color * intensity;
}

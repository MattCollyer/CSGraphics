#include "World.h"
#include "Sphere.h"
World::World(){
	std::vector <std::shared_ptr<Object>>  objects;
	std::vector <std::shared_ptr<Light>>  lights;
}
World World::defaultWorld(){
	World w;
	w.addLight(std::make_shared<Light>(Tuple::Point(-10, 10, -10), Tuple::Color(1, 1, 1)));
	std::shared_ptr <Sphere> sphere1 = std::make_shared<Sphere>();
	Material m1;
	m1.color = Tuple::Color(0.8, 1, 0.6);
	m1.diffuse = 0.7;
	m1.specular = 0.2;
	m1.ambient = 0.1;
	m1.indexOfRefraction = 1;
	sphere1->material = m1;
	w.addObject(sphere1);

	std::shared_ptr <Sphere> sphere2 = std::make_shared<Sphere>();
	sphere2->scale(0.5, 0.5, 0.5);
	Material m2;
	m2.color = Tuple::Color(1, 1, 1);
	m2.diffuse = 0.9;
	m2.specular = 0.9;
	m2.ambient = 0.1;
	m2.indexOfRefraction = 1;
	sphere2->material = m2;
	w.addObject(sphere2);
	return w;
}
std::vector <std::shared_ptr<Light>>  World::getLights(){
	return this->lights;
}
std::shared_ptr<Object> World::getObject(int i){
	return objects[i];
}

std::vector <std::shared_ptr<Object>> World::getObjects(){
	return objects;
}
void World::addObject(std::shared_ptr<Object> o){
	objects.push_back(o);
}
void World::addLight(std::shared_ptr<Light> l){
	lights.push_back(l);
}

std::vector <Intersection> World::intersectWorld(Ray ray){
	std::vector<Intersection> worldIntersections;
	for(int i = 0; i < objects.size(); i++){
		std::vector<double> intersections = objects[i]->intersectionsWith(ray);
		for(int j = 0; j < intersections.size(); j++){
			worldIntersections.push_back(Intersection(intersections[j], ray, objects[i]));
		}
	}
	std::sort(worldIntersections.begin(), worldIntersections.end());
	return worldIntersections;
}

Tuple World::colorAtIntersection(Intersection intersection){
	HitRecord hitRecord = intersection.generateHitRecord();
	return shadeHit(hitRecord);
}

bool World::isShadowed(Light light, Tuple point){
	Tuple vector = light.getPosition() - point;
	double distance = vector.getMagnitude();
	Tuple direction = vector.normalize();
	Ray ray(point, direction);
	std::vector <Intersection> intersections = this->intersectWorld(ray);
	for(int i = 0; i < intersections.size(); i++){
		if(intersections[i].getT() > 0 && intersections[i].getT() < distance){
			return true;
		}
	}
	return false;
}

Tuple World::shadeHit(HitRecord hitRecord){
	Tuple surfaceColor = Tuple::Color(0,0,0);
	for (int i = 0; i < lights.size(); i++){
		Light light = *lights[i];
		bool shadowed = isShadowed(light, hitRecord.overPoint);
		std::cout << shadowed;
		surfaceColor = surfaceColor + hitRecord.object->material.colorAtPoint(hitRecord, light, shadowed);
	}

	surfaceColor.clamp();
	return surfaceColor;
}

Tuple World::colorForRay(Ray ray){
	std::vector<Intersection> intersections = this->intersectWorld(ray);
	Tuple black = Tuple::Color(0, 0, 0);
	for(int i = 0; i < intersections.size(); i++){
		if (intersections[i].getT() > 0){
			return this->colorAtIntersection(intersections[i]);
		}
	}
	return black;
}

// Tuple World::reflectedColor(hitRecord){
// 	double reflective = hitRecord.object->material.reflective;
// 	if (reflective == 0){
// 		return Tuple::Color(0, 0, 0);
// 	}
// 	Ray reflect(hitRecord.overPoint, hitRecord.reflectV);
// 	Tuple color = colorForRay(hitRecord.ray, );
// 	return color * reflective;
// }

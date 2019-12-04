#include "World.h"
#include "Sphere.h"
World::World(){
	std::vector <Object *> objects;
	std::vector <Light *> lights;
}
World World::defaultWorld(){
	World w;
	Light light (Tuple::Point(-10, 10, -10), Tuple::Color(1, 1, 1));
	w.addLight(&light);
	Sphere sphere1;
	Material m1;
	m1.color = Tuple::Color(0.8, 1, 0.6);
	m1.diffuse = 0.7;
	m1.specular = 0.2;
	m1.ambient = 0.1;
	m1.indexOfRefraction = 1;
	sphere1.material = m1;
	w.addObject(&sphere1);

	Sphere sphere2;
	sphere2.scale(0.5, 0.5, 0.5);
	Material m2;
	m2.color = Tuple::Color(1, 1, 1);
	m2.diffuse = 0.9;
	m2.specular = 0.9;
	m2.ambient = 0.1;
	m2.indexOfRefraction = 1;
	sphere2.material = m2;
	w.addObject(&sphere2);
	return w;
}
std::vector <Light *> World::getLights(){
	return this->lights;
}
// Light * World::getLight(int index){
// 	if (index <= lights.size() && lights.size() != 0){
// 		return this->lights[index];
// 	}
// 	else{
// 		return nullptr;
// 	}
// }
//
// Object * World::getObject(int index){
// 	if (index <= objects.size() && objects.size() != 0){
// 		return this->objects[index];
// 	}
// 	else{
// 		return nullptr;
// 	}
// }

std::vector <Object *> World::getObjects(){
	return objects;
}
void World::addObject(Object* o){
	objects.push_back(o);
}
void World::addLight(Light* l){
	lights.push_back(l);
}

std::vector <Intersection> World::intersectionsWith(Ray ray){
	std::vector<Intersection> intersections;
	for(int i = 0; i < objects.size(); i++){
		std::vector<Intersection> intersection = objects[i]->intersectionsWith(ray);
		for(int j = 0; j < intersection.size(); j++){
			intersections.push_back(intersection[j]);
		}
	}
	std::sort(intersections.begin(), intersections.end());
	return intersections;
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
	std::vector <Intersection> intersections = this->intersectionsWith(ray);
	for(int i = 0; i < intersections.size(); i++){
		if(intersections[i].getT() > 0 && intersections[i].getT() < distance){
			return true;
		}
	}
	return false;
}

Tuple World::shadeHit(HitRecord hitRecord){
	Tuple finalColor = Tuple::Color(0,0,0);
	for (int i = 0; i < lights.size(); i++){
		Light light = *lights[i];
		bool shadowed = isShadowed(light, hitRecord.overPoint);
		finalColor = finalColor + hitRecord.object->material.colorAtPoint(hitRecord, light, shadowed);
	}
	finalColor.clamp();
	return finalColor;
}

// Tuple World::colorForRay(Ray r);

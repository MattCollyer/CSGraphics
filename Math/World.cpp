#include "World.h"

World::World(){
	std::vector <Object *> objects;
	std::vector <Light *> lights;
}
std::vector <Light *> World::getLights(){
	return this->lights;
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
	// HitRecord hitRecord = intersection.generateHitRecord();
	HitRecord hitRecord(Tuple::Point(1, 0, 1), Tuple::Vector(0, 1, 0), Tuple::Vector(1, 0, 1), true, Tuple::Point(1, 1, 1));
	return intersection.getObject().material.colorAtPoint(hitRecord, lights);
}



// Tuple World::colorForRay(Ray r);

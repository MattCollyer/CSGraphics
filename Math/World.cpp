#include "World.h"

World::World(){
	std::vector <Object> objects;
	std::vector <Light> lights;
}
std::vector <Light> World::getLights(){
	return this->lights;
}
void World::addObject(Object o){
	this->objects.push_back(o);
}
void World::addLight(Light l){
	this->lights.push_back(l);
}
std::vector <Intersection> World::intersectionsWith(Ray ray){
	std::vector<Intersection> intersections;
	for(int i = 0; i < this->objects.size(); i++){
		std::vector<Intersection> intersection = objects[i].intersectionsWith(ray);
		for(int j = 0; j < intersection.size(); j++){
			intersections.push_back(intersection[j]);
		}
	}
	return std::sort(intersections.begin(), intersections.end());
}

Tuple World::colorAtIntersection(Intersection intersection){
	HitRecord hitRecord = intersection.generateHitRecord();
	return intersection.getObject().getMaterial().colorAtPoint(hitRecord);
}





// Tuple World::colorForRay(Ray r);

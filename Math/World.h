#ifndef World_H
#define World_H
#include "Tuple.h"
#include "Object.h"
#include "Intersection.h"
#include "Light.h"
#include "Ray.h"

class World{
	private:
		std::vector <std::shared_ptr<Object>>  objects;
		std::vector <std::shared_ptr<Light>>  lights;

	public:
		World();
		static World defaultWorld();
		std::vector <std::shared_ptr<Light>> getLights();
		std::vector <std::shared_ptr<Object>> getObjects();
		std::shared_ptr<Object> getObject(int i);
		void addObject(std::shared_ptr<Object> o);
		void addLight(std::shared_ptr<Light> l);
		std::vector <Intersection> intersectWorld(Ray r);
		Tuple colorAtIntersection(Intersection i, int remaining);
		Tuple colorForRay(Ray r, int remaining);
		bool isShadowed(Light l, Tuple p);
		Tuple shadeHit(HitRecord h, int remaining);
		Tuple reflectedColor(HitRecord h, int remaining);
};

#endif

#ifndef World_H
#define World_H
#include "Tuple.h"
#include "Object.h"
#include "Intersection.h"
#include "Light.h"
#include "Ray.h"

class World{
	private:
		std::vector <Object *> objects;
		std::vector <Light *> lights;

	public:
		World();
		static World defaultWorld();
		std::vector <Light *> getLights();
		// Light * getLight(int index);
		std::vector <Object *> getObjects();
		// Object * getObject(int index);
		void addObject(Object* o);
		void addLight(Light* l);
		std::vector <Intersection> intersectionsWith(Ray r);
		Tuple colorAtIntersection(Intersection i);
		Tuple colorForRay(Ray r);
		bool isShadowed(Light l, Tuple p);
		Tuple shadeHit(HitRecord h);
};

#endif

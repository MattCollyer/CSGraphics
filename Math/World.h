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
		std::vector <Light *> getLights();
		void addObject(Object* o);
		void addLight(Light* l);
		std::vector <Intersection> intersectionsWith(Ray r);
		Tuple colorAtIntersection(Intersection i);
		Tuple colorForRay(Ray r);
};

#endif

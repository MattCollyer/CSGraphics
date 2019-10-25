#ifndef World_H
#define World_H

class World{
	private:
		std::vector <Object> objects;
		std::vector <Light> lights;

	public:
		intersectionsWith(Ray r);
		addObject(Object o);
		addLight(Light l);
		colorAtIntersection(Intersection i);

};

#endif

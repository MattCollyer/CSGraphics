#include <math.h>
#include "Math/World.h"
#include "Math/Plane.h"
#include "Math/Sphere.h"
#include "Math/Triangle.h"
#include "Math/Tuple.h"
#include "Math/Light.h"
#include "Math/Canvas.h"
#include "Math/Camera.h"
#include "Math/Mesh.h"
int main(int argc, char **argv)
{
	World myWorld = World::defaultWorld();

	std::shared_ptr <Plane> bottom = std::make_shared<Plane>();
	bottom->material.color = Tuple::Color(0, .2, .5);
	bottom->translate(5, -1, 10);
	myWorld.addObject(bottom);
	std::shared_ptr <Plane> wall = std::make_shared<Plane>();
	wall->material.color = Tuple::Color(.4, .05, .05);
	wall->rotateX(90);
	wall->translate(0, 0, -15);
	myWorld.addObject(wall);
	std::vector<std::shared_ptr <Object>> objects = myWorld.getObjects();
	std::shared_ptr <Sphere> smallSphere = std::make_shared<Sphere>();
	smallSphere->scale(0.5, 0.5, 0.5);
	smallSphere->translate(1.7, 4, -2);
	smallSphere->material.reflectivity = 0.7;
	smallSphere->material.color = Tuple::Color(1, 0.8, 0.1);
	myWorld.addObject(smallSphere);
	std::shared_ptr <Light> yellowLight = std::make_shared<Light>(Tuple::Point(10, 10, -10), Tuple::Color(.3, .3, 0));
	myWorld.addLight(yellowLight);
	myWorld.addObject(std::make_shared<Triangle>(Tuple::Point(-3, -1, -2), Tuple::Point(-2, 4, -2), Tuple::Point(-1.3, -1, -2)));
	Camera camera(2000, 2000, 60);
	camera.setTransform(camera.viewTransform(Tuple::Point(0, 1.5, -5), Tuple::Point(0, 1, 0), Tuple::Vector(0, 1, 0)));
	// camera.render(myWorld, "thisisatest");
	// Mesh m;
	// m.importOBJ("test1.obj");
	// m.makeMesh(&myWorld);
	camera.render(myWorld, "isurehopethisworks");

}

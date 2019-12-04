#include <math.h>
#include "Math/World.h"
#include "Math/Plane.h"
#include "Math/Sphere.h"
#include "Math/Tuple.h"
#include "Math/Light.h"
#include "Math/Canvas.h"
#include "Math/Camera.h"

int main(int argc, char **argv)
{
	World myWorld;

	Plane floor;
	floor.material.color = Tuple::Color(.2, .2, 1);
	// floor.translate(0, -5, 10);
	myWorld.addObject(&floor);

	Plane leftWall;
	leftWall.material.color = Tuple::Color(1, 0, 0);

	leftWall.translate(0, 0, 10);
	leftWall.rotateX(M_PI/2);
	myWorld.addObject(&leftWall);
	Plane rightWall;
	rightWall.material.color = Tuple::Color(1, 0, 0);
	rightWall.translate(0,0,5);
	rightWall.rotateY(M_PI/4);
	rightWall.rotateX(M_PI/2);
	rightWall.scale(10, 0.01, 10);
	myWorld.addObject(&rightWall);
	Sphere middle;
	middle.translate(-0.5, 1, 0.5);
	middle.material.color = Tuple::Color(0.1, 1, 0.5);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;
	myWorld.addObject(&middle);
	Sphere right = middle;
	right.translate(1.5, 0.5, -0.5);
	right.scale(0.5, 0.5, 0.5);
	right.material.color = Tuple::Color(0.5, 1, 0.1);
	myWorld.addObject(&right);
	Sphere left = middle;
	left.translate(-1.5, 0.33, -0.75);
	left.scale(0.33, 0.33, 0.33);
	left.material.color = Tuple::Color(1, 0.8, 0.1);
	myWorld.addObject(&left);
	Light light(Tuple::Point(-1, 10, -10), Tuple::Color(1, 1, 1));
	myWorld.addLight(&light);
	// Light light2(Tuple::Point(-10, 5, -5), Tuple::Color(.5, .1, .1));
	// myWorld.addLight(&light2);
	// Light light3(Tuple::Point(-3, -20, -4), Tuple::Color(.5, .5, 0));
	// myWorld.addLight(&light3);
	Camera camera(100, 100, 1.04719666667);
	camera.setTransform(camera.viewTransform(Tuple::Point(0, 1.5, -5), Tuple::Point(0, 1, 0), Tuple::Vector(0, 1, 0)));
	camera.render(myWorld, "thisisatest");

}

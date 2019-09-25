#define CATCH_CONFIG_MAIN
#include "../catch2.h"
#include <math.h>
#include "../Math/Math.cpp"


		
	TEST_CASE("creating tuple", "[Tuple]"){
		Tuple toople(4.3, -4.2, 3.1, 1.0);
    		REQUIRE(toople.isPoint());
		REQUIRE(!toople.isVector());
		REQUIRE(toople.getX() == 4.3);
		REQUIRE(toople.getY() == -4.2);
		REQUIRE(toople.getZ() == 3.1);
		REQUIRE(toople.getW() == 1.0);
	}

	TEST_CASE("its a vector", "[Tuple]") {
		Tuple toople(4.3, -4.2, 3.1, 0.0);
		REQUIRE(toople.isVector());
		REQUIRE(!toople.isPoint());
		REQUIRE(toople.getX() == 4.3);
		REQUIRE(toople.getY() == -4.2);
		REQUIRE(toople.getZ() == 3.1);
		REQUIRE(toople.getW() == 0.0);
	}
	
	TEST_CASE("point function thing", "[Tuple]"){
		Tuple point = Point(4, -4, 3);
		Tuple toople (4, -4, 3, 1);
		REQUIRE(point == toople);
	}
	
	TEST_CASE("vector function thing", "[Tuple]"){
		Tuple vector = Vector(4, -4, 3);
		Tuple toople (4, -4, 3, 0);
		REQUIRE(vector == toople);
	}

	TEST_CASE("addition overload", "[Tuple]"){
		Tuple tuple1 (3, -2, 5, 1);
    		Tuple tuple2 (-2, 3, 1, 0);
		Tuple tuple3 (1, 1, 6, 1);
		REQUIRE(tuple1 + tuple2 == tuple3);
	}
	
	TEST_CASE("subtraction overload", "[Tuple]"){
                Tuple point1 = Point(3, 2, 1);
    		Tuple point2 = Point(5, 6, 7);
		Tuple vector1 = Vector(-2, -4, -6);
  		REQUIRE(point1 - point2 == vector1);
   		Tuple vector2 = Vector(5, 6, 7);
		Tuple point3 = Point(-2, -4, -6);
		REQUIRE(point1 - vector2 == point3);
		Tuple zero = Vector(0, 0, 0);
		Tuple vector4 = Vector(1, -2, 3);
		REQUIRE(zero - vector4 == Vector(-1, 2, -3));
		
	}
	
	TEST_CASE("negation overload", "[Tuple]"){
		Tuple tuple1(1, -2, 3, -4);
		REQUIRE(-tuple1 == Tuple (-1, 2, -3, 4));
	}

	TEST_CASE("multiplication overload", "[Tuple]"){
		Tuple tuple1(1, -2, 3, -4);
		REQUIRE(tuple1 * 3.5  == Tuple(3.5, -7, 10.5, -14));
		REQUIRE(tuple1 * 0.5 == Tuple(0.5, -1, 1.5, -2));
	}

	TEST_CASE("division overload", "[Tuple]"){
		Tuple tuple1(1, -2, 3, -4);
		REQUIRE(tuple1 / 2 == Tuple (0.5, -1, 1.5, -2));
	}

	TEST_CASE("magnitude function", "[Tuple]"){
		Tuple vector1 = Vector(1, 0, 0);
		Tuple vector2 = Vector(0, 1, 0);
		Tuple vector3 = Vector(0, 0, 1);
		Tuple vector4 = Vector(1, 2, 3);
		Tuple vector5 = Vector(-1, -2, -3);
		REQUIRE(vector1.getMagnitude() == 1);
		REQUIRE(vector2.getMagnitude() == 1);
		REQUIRE(vector3.getMagnitude() == 1);
		REQUIRE(vector4.getMagnitude() == sqrt(14));
		REQUIRE(vector4.getMagnitude() == sqrt(14));
	}

	TEST_CASE("normalize function", "[Tuple]"){
		Tuple vector1 = Vector(4, 0, 0);
		Tuple vector2 = Vector(1, 2, 3);
		REQUIRE(vector1.normalize() == Vector(1, 0, 0));
		REQUIRE(vector2.normalize() == Vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
		REQUIRE(vector2.normalize().getMagnitude() == 1);
	}
	
	TEST_CASE("dot product function", "[Tuple]"){
		Tuple vector1 = Vector(1, 2, 3);
		Tuple vector2 = Vector(2, 3, 4);
		REQUIRE(dotProduct(vector1, vector2) == 20);
	}

	TEST_CASE("cross product function", "[Tuple]"){
		Tuple vector1 = Vector(1, 2, 3);
		Tuple vector2 = Vector(2, 3, 4);
		REQUIRE(crossProduct(vector2, vector1) == Vector(1, -2, 1));
	}

	TEST_CASE("color magic", "[Tuple]"){
		Tuple color1 = Color(-0.5, 0.4, 1.7);
		REQUIRE(color1.getX() == -0.5);
		REQUIRE(color1.getY() == 0.4);
		REQUIRE(color1.getZ() == 1.7);
		Tuple color2 = Color(0.9, 0.6, 0.75);
		Tuple color3 = Color(0.7, 0.1, 0.25);
		REQUIRE(color2 + color3 == Color(1.6, 0.7, 1.0));
		REQUIRE(color2 - color3 == Color(0.2, 0.5, 0.5));
		Tuple color4 = Color(0.2, 0.3, 0.4);
		REQUIRE(color4 * 2 == Color(0.4, 0.6, 0.8));
		Tuple color5 = Color(1, 0.2, 0.4);
    		Tuple color6 = Color(0.9, 1, 0.1);
		REQUIRE(color5 * color6 == Color(0.9, 0.2, 0.04));
	}

        TEST_CASE("testing ray", "[Ray]"){
                Tuple origin = Point(1, 2, 3);
                Tuple direction = Vector(4, 5, 6);
                Ray ray1 (Point(1, 2, 3), Vector(4, 5, 6));
                REQUIRE(ray1.getOrigin() == origin);
                REQUIRE(ray1.getDirection() == direction);
        	Ray ray2 (Point(2, 3, 4), Vector(1, 0, 0));
		REQUIRE(ray2.pointAtT(0) == Point(2, 3, 4));
		REQUIRE(ray2.pointAtT(1) == Point(3, 3, 4));
		REQUIRE(ray2.pointAtT(-1) == Point(1, 3, 4));
		REQUIRE(ray2.pointAtT(2.5) == Point(4.5, 3, 4));
	}
	TEST_CASE("sphere tests", "[Sphere]"){
		Ray ray(Point(0, 0, -5), Vector(0, 0, 1));
		Sphere sphere(Material(Color(1, 1, 1), 1));
		std::vector <double> tVals; 
		tVals = sphere.intersectionsWith(ray);
		REQUIRE(tVals.size() == 2);
		REQUIRE(tVals[0] == 4.0);
		REQUIRE(tVals[1] == 6.0);
		Ray ray2(Point(0, 1, -5), Vector(0, 0, 1));
		tVals = sphere.intersectionsWith(ray2);
		REQUIRE(tVals[0] == 5.0);
		REQUIRE(tVals[1] == 5.0);
		Ray ray3(Point(0, -2, -5), Vector(0, 0, 1));
		tVals = sphere.intersectionsWith(ray3);
		REQUIRE(tVals.empty());
		Ray ray4(Point(0, 0, 0), Vector(0, 0, 1));
		tVals = sphere.intersectionsWith(ray4);
		REQUIRE(tVals[0] == -1.0);
		REQUIRE(tVals[1] == 1.0);
		Ray ray5(Point(0, 0, 5), Vector(0,0,1));
		tVals = sphere.intersectionsWith(ray5);
		REQUIRE(tVals[0] == -6.0);
		REQUIRE(tVals[1] == -4.0);		

	}
	TEST_CASE("canvas tests", "[Canvas]"){
		Canvas canvas(10, 20);	
		REQUIRE(canvas.getWidth() == 10);
		REQUIRE(canvas.getHeight() == 20);
		Tuple black = Color(0, 0, 0);
		REQUIRE(canvas.pixelAt(4, 7) == black);
		REQUIRE(canvas.pixelAt(8, 3) == black);
		REQUIRE(canvas.pixelAt(5, 2) == black);
		Tuple red = Color(1, 0, 0);
		canvas.writePixel(2, 3, red);
		REQUIRE(canvas.pixelAt(2, 3) == red);
		Canvas canvas2(5, 3);
		canvas2.exportPpm();
	
	}
	TEST_CASE("light test", "[Light]"){
		Tuple color = Color(1, 1, 1);
		Tuple position = Point(0, 0, 0);
		Light light(position, color);
		REQUIRE(light.getPosition() == position);
		REQUIRE(light.getColor() == color);
	}
	TEST_CASE("Material Tests", "[Material]"){
		Material material;
		Sphere sphere (material);
		Tuple hitPoint = Point(0, 0, 0);
		REQUIRE(material.getColor() == Color(1, 1, 1));
		REQUIRE(material.getDiffuse() == 1);
		Light light(Point(0, 0, -10), Color(1, 1, 1));
		Tuple unitVectorToLight = (light.getPosition() - hitPoint).normalize();
		Tuple normal = Vector(0, 0, -1);
		REQUIRE(sphere.getMaterial().colorAtPoint(light, hitPoint, unitVectorToLight, normal) == Color(1, 1, 1));
		Light light2(Point(0, 10, -10), Color(1, 1, 1));
		Tuple unitVectorToLight2 = (light2.getPosition() - hitPoint).normalize();
		REQUIRE(sphere.getMaterial().colorAtPoint(light2, hitPoint, unitVectorToLight2, normal) == Color(sqrt(2)/2, sqrt(2)/2, sqrt(2)/2));
		Light light3(Point(0, 0, 10), Color(1, 1, 1));
		Tuple unitVectorToLight3 = (light3.getPosition() - hitPoint).normalize();
		//REQUIRE(sphere.getMaterial().colorAtPoint(light3, hitPoint, unitVectorToLight3, normal) == Color(0, 0, 0));
		Tuple bob = sphere.getMaterial().colorAtPoint(light3, hitPoint, unitVectorToLight3, normal);
		std::cout<<bob.getX();
		std::cout<<bob.getY();
		std::cout<<bob.getZ();
	}

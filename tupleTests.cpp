#define CATCH_CONFIG_MAIN
#include "catch2.h"
#include <math.h>
#include "./Math/Tuple.cpp"

	TEST_CASE( "its a point", "[Tuple]" ) {
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

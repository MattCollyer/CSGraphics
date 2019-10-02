#define CATCH_CONFIG_MAIN
#include "catch2.h"
#include <math.h>
#include "Math/Math.cpp"


		
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
		Material m (Color(0, 0, 1), 1);
		Sphere sphere(m);
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
		//New Tests
		REQUIRE(sphere.normalAtPoint(Point(1, 0, 0)) == Vector(1, 0, 0));
		REQUIRE(sphere.normalAtPoint(Point(0, 1, 0)) == Vector(0, 1, 0));
		REQUIRE(sphere.normalAtPoint(Point(0, 0, 1)) == Vector(0, 0, 1));
		Tuple normalNonaxial = sphere.normalAtPoint(Point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
		REQUIRE(normalNonaxial == Vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
		REQUIRE(normalNonaxial == normalNonaxial.normalize());
		REQUIRE(sphere.getMaterial().getColor() == Color(0, 0, 1));
		REQUIRE(sphere.getMaterial() == m);

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
		REQUIRE(sphere.getMaterial().colorAtPoint(light3, hitPoint, unitVectorToLight3, normal) == Color(0, 0, 0));
		Tuple bob = sphere.getMaterial().colorAtPoint(light3, hitPoint, unitVectorToLight3, normal);
		std::cout<<bob.getX();
		std::cout<<bob.getY();
		std::cout<<bob.getZ();
	}
	TEST_CASE("Matrix Tests", "[Matrix]"){
		Matrix matrix1(4, 4);
		double arr1[16] = {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 0, 0, 0, 1};
		matrix1.fromArray(arr1);
		REQUIRE(matrix1.getValue(0, 0) == 1);
		REQUIRE(matrix1.getValue(0, 3) == 4);
		REQUIRE(matrix1.getValue(1, 0) == 5.5);
		REQUIRE(matrix1.getValue(1, 2) == 7.5);
		REQUIRE(matrix1.getValue(2, 2) == 11);
		REQUIRE(matrix1.getValue(3, 0) == 0);
		REQUIRE(matrix1.getValue(3, 3) == 1);
		Matrix matrix2(2, 2);
		double arr2[4] = {-3, 5, 1, -2};
		matrix2.fromArray(arr2);
		REQUIRE(matrix2.getValue(0, 0) == -3);
		REQUIRE(matrix2.getValue(0, 1) == 5);
		REQUIRE(matrix2.getValue(1, 0) == 1);
		REQUIRE(matrix2.getValue(1, 1) == -2);
		Matrix matrix3(4, 4);
		double arr3[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 0, 0, 0, 1};
		matrix3.fromArray(arr3);
		Matrix matrix4(4, 4);
		matrix4.fromArray(arr3);
		REQUIRE(matrix3 == matrix4);
		double arr4[16] = {2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 0, 0, 0, 1};
		matrix4.fromArray(arr4);
		REQUIRE(matrix3 != matrix4);
		Matrix matrix5(4, 4);	
		double arr5[16] = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 0, 0, 0, 1};
		matrix5.fromArray(arr5);
		Matrix matrix6(4, 4);
		double arr6[16] = {16, 14, 22, 20, 36, 38, 58, 52, 34, 46, 68, 60, 0, 0, 0, 1};
		matrix6.fromArray(arr6);
		REQUIRE(matrix3 * matrix5 == matrix6);
		Matrix matrix7(4, 4);
		double arr7[16] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
		matrix7.fromArray(arr7);
		Tuple tuple1(1, 2, 3, 1);
		REQUIRE(matrix7 * tuple1 == Tuple(18, 24, 33, 1));
		Matrix matrix8(4, 4);
		double arr8[16] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 0, 0, 0, 1};
		matrix8.fromArray(arr8);
		REQUIRE(matrix8 * Matrix::identity(4) == matrix8);
		Matrix matrix9(2, 2);
		double arr9[4] = {1, 5, -3, 2};
		matrix9.fromArray(arr9);
		REQUIRE(matrix9.determinant() == 17);
		Matrix matrix10(3, 3);
		double arr10[9] = {1, 5, 0, -3, 2, 7, 0, 6, -3};
		matrix10.fromArray(arr10);
		Matrix  matrix11(2, 2);
		double arr11[4] = {-3, 2, 0, 6};
		matrix11.fromArray(arr11);
		REQUIRE(matrix10.submatrix(0, 2) == matrix11);
		Matrix matrix12(3, 3);
		double arr12[9] = {3, 5, 0, 2, -1, -7, 6, -1, 5};
		matrix12.fromArray(arr12);
		REQUIRE(matrix12.submatrix(1, 0).determinant() == 25);
		REQUIRE(matrix12.minor(1, 0) == 25);
		REQUIRE(matrix12.minor(0, 0) == -12);
		REQUIRE(matrix12.cofactor(0, 0) == -12);
		REQUIRE(matrix12.minor(1, 0) == 25);
		REQUIRE(matrix12.cofactor(1, 0) == -25);
		Matrix matrix13(3, 3);
		double arr13[9] = {1, 2, 6, -5, 8, -4, 2, 6, 4};
		matrix13.fromArray(arr13);
		REQUIRE(matrix13.cofactor(0, 0) == 56);
		REQUIRE(matrix13.cofactor(0, 1) == 12);
		REQUIRE(matrix13.cofactor(0, 2) == -46);
		REQUIRE(matrix13.determinant() == -196);
		Matrix matrix14(4, 4);
		double arr14[16] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, 0, 0, 0, 1};
		matrix14.fromArray(arr14);
		REQUIRE(matrix14.determinant() == 185);
		Matrix matrix15(4, 4);
		double arr15[16] = {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6};
		matrix15.fromArray(arr15);
		REQUIRE(matrix15.determinant() == -2120);
		REQUIRE(matrix15.isInvertible());
		Matrix matrix16(4, 4);
		double arr16[16] = {-4, 2, 0, -3, 9, 6, 0, 6, 0, -5, 0, -5, 0, 0, 0, 1};
		matrix16.fromArray(arr16);
		REQUIRE(matrix16.determinant() == 0);
		REQUIRE(!matrix16.isInvertible());
		Matrix matrix17(4, 4);
		double arr17[16] = {-5, 2, 6,-8, 1, -5, 1, 8, 7, 7, -6, -7, 0, 0, 0, 1};
		matrix17.fromArray(arr17);
		Matrix matrix18(4, 4);
		double arr18[16] = {0.14110, 0.33129, 0.19632, -0.14724, 0.07975, -0.07362, 0.06748, 1.69939, 0.25767, 0.30061, 0.14110, 0.64417, 0.0, 0.0, 0.0, 1.0};
		matrix18.fromArray(arr18);
		REQUIRE(matrix17.inverse() == matrix18);
		Matrix matrix19(4, 4); 
		double arr19[16] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, 0, 0, 0, 1};
		matrix19.fromArray(arr19);
		Matrix matrix20(4, 4);
		double arr20[16] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 0, 0, 0, 1};
		matrix20.fromArray(arr20);
		Matrix matrix21 = matrix19 * matrix20;
		REQUIRE(matrix21 * matrix20.inverse() == matrix19);
	}	

#ifndef Tuple_H
#define Tuple_H
#include <iostream>
class Tuple{

	private:
		double x;
		double y;
		double z;
		double w;
	public:
		Tuple(double x, double y, double z, double w);
		double getX() const;
		double getY() const;
		double getZ() const;
		double getW() const;
		void setW(double w);
		bool isPoint();
		bool isVector();
		double getMagnitude();
		Tuple normalize();
		static Tuple reflect(Tuple vector, Tuple normal);
		static Tuple Point(double x, double y, double z);
		static Tuple Vector(double x, double y, double z);
		static Tuple Color(double red, double green, double blue);
		static double dotProduct(Tuple a, Tuple b);
		static Tuple crossProduct(Tuple a, Tuple b);
		bool operator==(const Tuple& other) const;
		void operator+=(const Tuple& other) const;
		Tuple operator+(const Tuple& other) const;
		Tuple operator-(const Tuple& other) const;
		Tuple operator-() const;
		Tuple operator*(const double& other) const;
		Tuple operator*(const Tuple& other) const;
		Tuple operator/(const double& other) const;

};


// For catch2
std::ostream& operator << ( std::ostream& os, Tuple const& obj);

#endif

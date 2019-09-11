#include <math.h>

class Tuple{

private:
	double x;
	double y;
	double z;
	double w;
public:
	Tuple(double x, double y, double z, double w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	double getX() const{
		return x;
	}

	double getY() const{
		return y;
	}

	double getZ() const{
		return z;
	}

	double getW() const{
		return w;
	}

	bool isPoint(){
		return w == 1.0;
	}
	
	bool isVector(){
		return w == 0.0;
	}
	
	double getMagnitude(){
		return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0) + pow(this->z, 2.0));
	}

	Tuple normalize(){
		double mag = this->getMagnitude();
		return Tuple (this->x/mag, this->y/mag, this->z/mag, 0.0);
	}
	
	bool operator==(const Tuple& other) const{
		return (this->x == other.getX() && this->y == other.getY() && this->z == other.getZ() && this->w == other.getW());
	}

	Tuple operator+(const Tuple& other) const{
		return  Tuple (this->x + other.getX(), this->y + other.getY(), this->z + other.getZ(), this->w + other.getW()); 
	}

	Tuple operator-(const Tuple& other) const{
		return Tuple (this->x - other.getX(), this->y - other.getY(), this->z - other.getZ(), this->w - other.getW());
	}
	
	Tuple operator-() const{
		return Tuple (-this->x, -this->y, -this->z, -this->w);
	}
	
	Tuple operator*(const double& other) const{
		return Tuple (other * this->x, other * this->y, other * this->z, other * this->w);
	}
	
	Tuple operator/(const double& other) const{
		return Tuple (this->x / other, this->y / other, this->z / other, this->w / other);
	}
	
};	

Tuple Point(double x, double y, double z){
	return Tuple(x, y, z, 1.0);
}
 
Tuple Vector(double x, double y, double z){
	return Tuple(x, y, z, 0.0);
}	

double dotProduct(Tuple a, Tuple b){
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

Tuple crossProduct(Tuple a, Tuple b){
	double x = a.getY() * b.getZ() - a.getZ() * b.getY();
	double y = a.getZ() * b.getX() - a.getX() * b.getZ();
	double z = a.getX() * b.getY() - a.getY() * b.getX();
	return Tuple(x, y, z, 0.0);
}

        




#ifndef Tuple_H
#define Tuple_H
  
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

        bool isPoint();

        bool isVector();

	double getMagnitude();

        Tuple normalize();

        bool operator==(const Tuple& other) const;

        Tuple operator+(const Tuple& other) const;

        Tuple operator-(const Tuple& other) const;

        Tuple operator-() const;

        Tuple operator*(const double& other) const;

        Tuple operator*(const Tuple& other) const;

        Tuple operator/(const double& other) const;

};

Tuple Point(double x, double y, double z);

Tuple Vector(double x, double y, double z);

Tuple Color(double red, double green, double blue);

double dotProduct(Tuple a, Tuple b);

Tuple crossProduct(Tuple a, Tuple b);
 
std::ostream& operator << ( std::ostream& os, Tuple const& obj ) {
	os << "x: " << obj.getX() << " y: " << obj.getY() << " z: " << obj.getZ() << " w: " << obj.getW();
	return os;
}

#endif

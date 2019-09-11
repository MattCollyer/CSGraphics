#include "Tuple.cpp"
#include "Ray.cpp"

class Sphere{

public:

	double[] intersectionsWith(Ray ray){
		Tuple o = ray.getOrigin() - Point(0,0,0);
		double b = 2*dotProduct(ray.getDirection(), o);
		double c = dotProduct(o, o) - 1;
		double discriminant = pow(b, 2) - 4 * c; 
		if(discriminant < 0){
			return [];
		}
		else{
			double t1 = (-b - sqrt(discriminant))/2;
			double t2 = (-b + sqrt(discriminant))/2;
			double tVals[2] = {t1, t2};
			return tVals;
		}
	}
};

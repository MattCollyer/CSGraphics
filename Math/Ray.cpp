#include "Tuple.cpp"
class Ray{


	private:

		Tuple origin;
		Tuple direction;

	public:

		Ray(Tuple o, Tuple d):origin(o), direction(d){
			this->origin = o;
			this->direction = d;
		}

		Tuple getOrigin() const{
			return this->origin;
		}
		
		Tuple getDirection() const{
			return this->direction;
		}

		Tuple pointAtT(double t){
			return this->direction * t + this->origin;
		}

};
				

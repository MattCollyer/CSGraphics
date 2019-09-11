#include "Tuple.cpp"
class Ray{


	private:

		Tuple origin;
		Tuple direction;

	public:
		Tuple getOrigin() const{
			return this->origin;
		}
		
		Tuple getDirection() const{
			return this->direction;
		}

		Tuple pointAtT(double t){
			return direction * t + origin;
		}

};
				

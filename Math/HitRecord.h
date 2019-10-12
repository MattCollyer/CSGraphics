#ifndef 
#define HitRecord_H

class HitRecord{

	private:
		Tuple hitPoint
		Tuple normalVector
		Tuple eyeVector
		bool isInside
	public:
		HitRecord(Tuple hitPoint, Tuple normalVector, Tuple eyeVector, bool isInside);


};

#endif

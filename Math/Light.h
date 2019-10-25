#ifndef Light_H
#define Light_H
#include "Tuple.h"
class Light{
	private:
		Tuple position; //point
		Tuple color;

	public:
		Light(Tuple p, Tuple c);
		Tuple getPosition();
		Tuple getColor();

};
#endif

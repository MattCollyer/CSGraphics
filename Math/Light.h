#ifndef Light_H
#define Light_H
#include "Tuple.h"
class Light{
	private:
		Tuple position;
		Tuple color;

	public:
		Light(Tuple p, Tuple c);
		Tuple getPosition();
		Tuple getColor();

};
#endif

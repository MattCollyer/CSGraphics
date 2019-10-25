#include "Light.h"

Light::Light(Tuple p, Tuple c):position(p), color(c){
	position = p;
	color = c;
}

Tuple Light::getPosition(){
	return position;
}

Tuple Light::getColor(){
	return color;
}

#ifndef Material_H
#define Material_H

class Material{
	private:
		Tuple color;
		double diffuse;
	public:
		Material();
		Material(Tuple c, double d);
		Tuple getColor();
		double getDiffuse();
		Tuple colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal);
};

#endif 

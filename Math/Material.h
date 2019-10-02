#ifndef Material_H
#define Material_H

class Material{
	private:
		Tuple color;
		double diffuse;
	public:
		Material();
		Material(Tuple c, double d);
		Tuple getColor() const;
		double getDiffuse() const;
		Tuple colorAtPoint(Light light, Tuple position, Tuple unitVectorToLight, Tuple normal);
	        bool operator==(const Material& other) const;

};

#endif 

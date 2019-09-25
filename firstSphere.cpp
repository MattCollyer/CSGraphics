#include "Math/Math.cpp"
#include <stdio.h>

int main(){
	Canvas canvas(100, 100);
	Tuple red = Color(1, 0, 0);
	Material m;
	Sphere sphere(m);
	for(int i = 0; i < 100; i++){
		double y = 2 - (float)i/25;
		for(int j = 0; j < 100; j++){
			double x = -2 + (float)j/25;
			Tuple origin = Point(x, y, -5);
			Ray ray(origin, Vector(0, 0, 1));
			std::vector<double> tVals = sphere.intersectionsWith(ray);
			bool wasHit = false;
			for(int x = 0; x < tVals.size(); x++){
				if(tVals[x] > 0){
					wasHit = true;
				}
			}
			if(wasHit){
				canvas.writePixel(j, i, red);
			}
		}
	}	
	canvas.exportPpm();




return 0;
}

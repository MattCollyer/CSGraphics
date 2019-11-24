#ifndef Canvas_H
#define Canvas_H
#include "Tuple.h"
#include "World.h"
#include <vector>

class Canvas{
	private:
		int height;
		int width;
		std::vector <std::vector<Tuple>> canvas;
	public:
		Canvas(int x, int y);
		int getWidth();
		int getHeight();
		void writePixel(int x, int y, Tuple pixel);
		void render(World w);
		Tuple pixelAt(int x, int y);
		void exportPpm(std::string filename);


};





#endif

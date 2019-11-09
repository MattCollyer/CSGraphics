#include "Canvas.h"
#include <string>
#include <fstream>
#include <vector>

Canvas::Canvas(int x, int y){
	width = x;
	height = y;
	canvas = std::vector<std::vector<Tuple>>(height,  std::vector<Tuple>(width, Tuple::Color(0, 0, 0)));
}

int Canvas::getWidth(){
	return width;
}

int Canvas::getHeight(){
	return height;
}

void Canvas::writePixel(int x, int y, Tuple color){
	canvas[y][x] = color;
}

Tuple Canvas::pixelAt(int x, int y){
	return canvas[y][x];
}

void Canvas::exportPpm(){
	std::ofstream file;
	file.open("CSGRAPHICS.ppm");
	file << "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
	for (int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			file << std::to_string((int)(canvas[i][j].getX() * 255)) + " " + std::to_string((int)(canvas[i][j].getY() * 255)) + " " + std::to_string((int)(canvas[i][j].getZ() * 255)) + " ";
		}
	file << "\n";
	}
file.close();
}

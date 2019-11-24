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
void Canvas::render(World world){

	for (int i = 0; i < height; i++){
		double y = 2 - (float)i/(height/4);
		for (int j = 0; j < 100; j++){
			double x = -2 + (float)j/(width/4);
			Tuple origin = Tuple::Point(x, y, -5);
			Ray ray(origin, Tuple::Vector(0, 0, 1));
			std::vector<Intersection> intersections = world.intersectionsWith(ray);
			for(int p = 0; p < intersections.size(); p++){
				if (intersections[p].getT() < 0){
					writePixel(j, i, Tuple::Color(0, 0, 0));
				}
				else{
					Tuple color = world.colorAtIntersection(intersections[p]);
					writePixel(j, i, color);
				}
			}
		}
	}
}

void Canvas::exportPpm(std::string filename){
	std::ofstream file;
	file.open(filename + ".ppm");
	file << "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
	for (int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			file << std::to_string((int)(canvas[i][j].getX() * 255)) + " " + std::to_string((int)(canvas[i][j].getY() * 255)) + " " + std::to_string((int)(canvas[i][j].getZ() * 255)) + " ";
		}
	file << "\n";
	}
file.close();
}

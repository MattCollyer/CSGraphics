#ifndef Camera_H
#define Camera_H

#include "Matrix.h"
#include "Ray.h"
#include "World.h"

class Camera{
	private:
		int hsize;
		int vsize;
		double fov;
		double pixelS;
		double halfHeight;
		double halfWidth;
		Matrix transform;

	public:
		Camera(int h, int v, double f);
		void setHSize(int h);
		void setVSize(int v);
		void setFOV(double f);
		void setTransform(Matrix m);

		int getHSize();
		int getVSize();
		double getFOV();
		Matrix getTransform();
		Matrix viewTransform(Tuple from, Tuple to, Tuple up);
		double pixelSize();
		Ray rayForPixel(double x, double y);
		void render(World world, std::string filename);
};

#endif

#include "Camera.h"
#include <math.h>
#include "Canvas.h"

Camera::Camera(int h, int v, double f): hsize(h), vsize(v), fov(f), transform(Matrix::identity(4)){
	pixelS = pixelSize();
}

void Camera::setHSize(int h){
	this->hsize = h;
}
void Camera::setVSize(int v){
	this->vsize = v;
}
void Camera::setFOV(double f){
	this->fov = f;
}
void Camera::setTransform(Matrix m){
	this->transform = m;
}

int Camera::getHSize(){
	return hsize;
}
int Camera::getVSize(){
	return vsize;
}
double Camera::getFOV(){
	return fov;
}
Matrix Camera::getTransform(){
	return transform;
}

double Camera::pixelSize(){
	//fov to radians?
	double halfView = tan(fov / 2);
	double aspect = (double) hsize / (double) vsize;
	if (aspect >= 1 ){
		halfWidth = halfView;
		halfHeight = halfView / aspect;
	}
	else{
		halfWidth = halfView * aspect;
		halfHeight = halfView;
	}
	return ((halfWidth * 2) / hsize);

}

Ray Camera::rayForPixel(double x, double y){
	//The offset from the edge of the canvas to the pixel's center
	double xOffset = (x + 0.5) * pixelS;
	double yOffset = (y + 0.5) * pixelS;
	//The untransformed coords of the pixel in world space
	double worldX = (halfWidth - xOffset);
	double worldY = (halfHeight - yOffset);
	//using the camera matrix, transform canvas point and origin, then compute
	//the rays direcitons vector.
	Tuple pixel = transform.inverse() * Tuple::Point(worldX, worldY, -1);
	Tuple origin = transform.inverse() * Tuple::Point(0, 0, 0);
	Tuple direction = (pixel - origin).normalize();
	return Ray(origin, direction);
}

Matrix Camera::viewTransform(Tuple from, Tuple to, Tuple up){
	Tuple forward = (to - from).normalize();
	Tuple upNormal = up.normalize();
	Tuple left = Tuple::crossProduct(forward, upNormal);
	Tuple trueUp = Tuple::crossProduct(left, forward);

	Matrix orientation(4, 4);
	double orientationArr[16] = {left.getX(), left.getY(), left.getZ(), 0,
								trueUp.getX(), trueUp.getY(), trueUp.getZ(), 0,
								-forward.getX(), -forward.getY(), -forward.getZ(), 0,
								0,				0,					0,			1};
	orientation.fromArray(orientationArr);
	return orientation * Matrix::translation(-from.getX(), -from.getY(), -from.getZ());

}


void Camera::render(World world, std::string filename){
	Canvas canvas(hsize, vsize);

	for (int i = 0; i < vsize; i++){
		for (int j = 0; j < hsize; j++){
			Ray ray = rayForPixel(j, i);
			Tuple color = world.colorForRay(ray);
			canvas.writePixel(j, i, color);
		}
	}
	canvas.exportPpm(filename);
}

#include "MeshTriangle.h"

MeshTriangle::MeshTriangle(Tuple a, Tuple b, Tuple c, Mesh* m): Triangle(a, b, c), mesh(m){}

void MeshTriangle::setIndices(int a, int b, int c){
	vertexIndices[0] = a;
	vertexIndices[1] = b;
	vertexIndices[2] = c;
}

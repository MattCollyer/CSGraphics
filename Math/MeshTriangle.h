#ifndef MeshTriangle_H
#define MeshTriangle_H
#include "Triangle.h"
#include "Tuple.h"
#include "Mesh.h"

class MeshTriangle : public Triangle {
	private:
		Mesh* mesh;
		int vertexIndices[3];
		
	public:
		MeshTriangle(Tuple a, Tuple b, Tuple c, Mesh* m);
		void setIndices(int a, int b, int c);
};

#endif

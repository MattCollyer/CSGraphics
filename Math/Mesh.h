#ifndef Mesh_H
#define Mesh_H
#include "Tuple.h"
#include "World.h"
#include <vector>
class Mesh{
	public:
	std::vector <Tuple> vertices;
	std::vector <std::vector<int>> faces;
	void importOBJ(std::string filename);
	void makeMesh(World* w);
};



#endif

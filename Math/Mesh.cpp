#include "Mesh.h"
#include "MeshTriangle.h"


void Mesh::importOBJ(std::string filename){
	std::ifstream obj (filename);
	std::string line;
	if (obj.is_open())
	{
		 while ( getline (obj, line))
		{
			if(line.at(0) == 'f' || line.at(0) == 'v'){
				int space1 = line.find_first_of(' ', 2);
				std::string value1 = line.substr(2, space1 - 2);
				int space2 = line.find_first_of(' ', space1 + 1);
				std::string value2 = line.substr(space1 + 1, space2 - space1 - 1);
				int space3 = line.find_first_of(' ', space2 + 1);
				std::string value3 = line.substr(space2 + 1, space3 - space2);
				if(line.at(0) == 'v'){
					vertices.push_back(Tuple::Point(std::atof(value1.c_str()), std::atof(value2.c_str()), std::atof(value3.c_str())));
				}
				else if (line.at(0) == 'f'){
					std::vector <int> face;
					face.push_back(atoi(value1.c_str()) - 1);
					face.push_back(atoi(value2.c_str()) - 1);
					face.push_back(atoi(value2.c_str()) - 1);
					faces.push_back(face);
				}
			}
		}
		obj.close();
	}
	else std::cout << "Unable to open file";
}
void Mesh::makeMesh(World* w){
	for(int i = 0; i < faces.size(); i++){
		Tuple vertex1 = vertices[faces[i][0]];
		Tuple vertex2 = vertices[faces[i][1]];
		Tuple vertex3 = vertices[faces[i][2]];
		w->addObject(std::make_shared<MeshTriangle>(vertex1, vertex2, vertex3, this));
	}
}

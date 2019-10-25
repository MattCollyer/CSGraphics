CXX = clang++
CXXFLAGS = -I. -std=c++11

CPP =  $(wildcard Math/*.cpp)
OBJ = $(CPP:%.cpp=%.o)

tests : tests.cpp $(OBJ) 
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

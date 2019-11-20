CXX = clang++
CXXFLAGS = -I. -g -O0 -std=c++11

CPP =  $(wildcard Math/*.cpp)
OBJ = $(CPP:%.cpp=%.o)

tests : tests.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

render : render.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean :
	rm $(OBJ)

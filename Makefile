CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Iexternal


SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
OUT = arvore


all: $(OUT)


$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(OUT)

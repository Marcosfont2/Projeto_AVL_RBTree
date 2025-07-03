CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Iexternal
SRC = $(wildcard src/*.cpp)
OUT = arvore

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)

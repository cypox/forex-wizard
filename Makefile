CXX = g++

all: src/fxwiz.cpp
	mkdir bin/
	$(CXX) src/fxwiz.cpp -Iinclude -lcurl -o bin/fxwiz

clean:
	rm -rf bin/*

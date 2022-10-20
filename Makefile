CXX = g++

all: src/fxwiz.cpp
	mkdir -p bin/
	$(CXX) src/fxwiz.cpp -Iinclude -lcurl -o bin/fxwiz

clean:
	rm -rf bin/*

test:
	./bin/fxwiz https://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml

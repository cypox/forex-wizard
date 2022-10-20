CXX = g++

all: src/fxwiz.cpp
	mkdir -p bin/
	$(CXX) src/fxwiz.cpp -Iinclude -lcurl -o bin/fxwiz

clean:
	rm -rf bin/*

test:
	./bin/fxwiz https://www.oanda.com/currency-converter/live-exchange-rates/

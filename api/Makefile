all: build

build:
	g++ -std=c++17 -o http_server http_server.cpp -lboost_system -lpthread

clean:
	rm -rf http_server

rebuild: clean build
all: build

build:
	g++ -std=c++17 -o db db.cpp -lboost_system -lpthread

clean:
	rm -rf db

rebuild: clean build
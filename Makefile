target: run
	./run
run: os.cc
	g++ -std=c++11 -Os -Wall -pedantic os.cc -lboost_system -lboost_filesystem -o run

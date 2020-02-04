
CXX = g++
DUBUG = -Wall
main: main.o map.o bloc.o bomb.o player.o
	$(CXX) -o main main.o map.o bloc.o bomb.o player.o -lpthread

main.o : main.cpp
	$(CXX) -c $(DEBUG) main.cpp

map.o : map.cpp
	$(CXX) -c $(DEBUG) map.cpp

bloc.o : bloc.cpp
	$(CXX) -c $(DEBUG) bloc.cpp

bomb.o : bomb.cpp
	$(CXX) -c $(DEBUG) bomb.cpp

player.o : player.cpp
	$(CXX) -c $(DEBUG) player.cpp

clean :
	rm -f main *.o

clean_o :
	rm -f *.o
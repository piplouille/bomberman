
CXX = g++
main: main.o map.o bloc.o bomb.o player.o
	$(CXX) -o main main.o map.o bloc.o bomb.o player.o -lpthread

main.o : main.cpp
	$(CXX) -c -Wall main.cpp

map.o : map.cpp
	$(CXX) -c -Wall map.cpp

bloc.o : bloc.cpp
	$(CXX) -c -Wall bloc.cpp

bomb.o : bomb.cpp
	$(CXX) -c -Wall bomb.cpp

player.o : player.cpp
	$(CXX) -c -Wall player.cpp

clean :
	rm -f main *.o

clean_o :
	rm -f *.o
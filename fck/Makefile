main: main.o map.o bloc.o bomb.o player.o
	g++ -o main main.o map.o bloc.o bomb.o player.o -lpthread

main.o : main.cpp
	g++ -c -Wall main.cpp

map.o : map.cpp
	g++ -c -Wall map.cpp

bloc.o : bloc.cpp
	g++ -c -Wall bloc.cpp

bomb.o : bomb.cpp
	g++ -c -Wall bomb.cpp

player.o : player.cpp
	g++ -c -Wall player.cpp

clean :
	rm -f main *.o

clean_o :
	rm -f *.o
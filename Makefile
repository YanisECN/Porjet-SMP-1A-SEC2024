all : bataille_navale

rebuild : clean all

bataille_navale : main.o
	g++ -o bataille_navale main.o -g

main.o : source/main.cpp
	g++ -o main.o -c source/main.cpp -g


clean :
	del *.o

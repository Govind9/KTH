all: Main

dni.o:
	g++ dni.cpp -c

clean:
	rm -rf *.o
	rm -rf dni

Main: main.cpp dni.o
	g++ main.cpp dni.o -o dni

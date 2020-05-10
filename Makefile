projDriver: main.o
	g++ -o projDriver main.o -std=c++11

main.o: main.cpp Graph.cpp Graph.h
	g++ -c main.cpp -std=c++11

clean:
	rm main.o projDriver

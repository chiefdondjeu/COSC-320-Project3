imgSeg: main.o
	g++ -o imgSeg main.o -std=c++11

main.o: main.cpp Graph.h
	g++ -c main.cpp -std=c++11

clean:
	rm main.o imgSeg
/*
	Florent Dondjeu Tschoufack
	COSC 320-002
	Project 3
	main.cpp
	Apr 30, 2020
*/

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "The program requires two arguments!\nExiting...\n";
		exit(1);
	}

	std::ifstream infile;
	infile.open(argv[1]);

	Graph<char> myGraph;
	bool add = true;

	while(!infile.eof())
	{
		std::string line;
		std::getline(infile,line);
		
		if(line != "---" && add)
		{
			std::istringstream ss(line);
			char u;
			int w;

			ss >> u;
			ss >> w;
			myGraph.addVertex(u,w);
		}
		else
		{
			add = false;
			std::istringstream ss(line);
			char u, v;
			ss >> u;
			while(ss >> v)
				myGraph.addEdge(u,v);
		}

	}

	myGraph.print();
	myGraph.Segment();

	std::cout << "\nend of program. Existing...\n";
	std::cout << "========================================\n";

	/*Graph<char> myGraph;

	//pixels on the grids
	myGraph.addVertex('A',20);
	myGraph.addVertex('B',30);
	myGraph.addVertex('C',9);
	myGraph.addVertex('D',12);
	myGraph.addVertex('E',1);
	myGraph.addVertex('F',17);
	myGraph.addVertex('G',16);
	myGraph.addVertex('H',9);
	myGraph.addVertex('I',2);
	myGraph.addVertex('J',10);

	//pixels's edges
	myGraph.addEdge('A','B');
	myGraph.addEdge('A','C');
	myGraph.addEdge('A','I');

	myGraph.addEdge('B','C');
	myGraph.addEdge('B','J');
	myGraph.addEdge('B','E');

	myGraph.addEdge('C','D');

	myGraph.addEdge('D','E');
	myGraph.addEdge('D','F');

	myGraph.addEdge('E','J');
	myGraph.addEdge('E','H');

	myGraph.addEdge('F','G');
	myGraph.addEdge('G','H');

	myGraph.print();

	std::cout << "\n";
	myGraph.Segment();*/

	return 0;
}
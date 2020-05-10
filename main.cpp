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

	return 0;
}
/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	Project 3
	Graph.h
	May 1, 2020
*/

#ifndef GRAPH_PRJ_H
#define GRAPH_PRJ_H

#include<vector>
#include<map>
#include<iostream>
#include<algorithm>

template <class T>
class Graph
{
	private:

		struct Pixel
		{
			T data;	//other pixel
			double weight;	//difference in intensity between two pixels

			Pixel(T d, double w)
			{
				data = d;
				weight = w;
			}
		};

		std::map<T,std::vector<Pixel> > V; 	//pixel's edges
		std::map<T,double> W;	//pixels and their intensity

		//returns a positive difference of two numbers
		double difference(double&,double&);

		//helper function to print content stored in a vector
		void printVect(std::vector<Pixel>&);

		//helper function to search for an element in a vector
		bool isPresent(std::vector<T>,T);

		/* Algorithm functions */

		std::map<double,std::pair<T,T> > pi;	//edge's intensity

		//determines if two elements are in different components
		//return true if element are in different component
		//returns false if elements are in the same component
		bool isDisjoint(std::vector<std::vector<T> >,T,T);

		//controls the degree of difference between two components
		double tau(int);

		//add all the weight of each element in a component
		//returns the minimun of the two
		double internal_difference(std::vector<std::vector<T> >, T,T);

		//combines the pixel from two components into one 
		void merge(std::vector<std::vector<T> >&, T,T);


	public:

		Graph();

		~Graph();

		//adds a pixel to the graph
		void addVertex(T,double);

		//adds an undirected edge between 2 pixels
		void addEdge(T,T);

		//prints all pixels along with their intensity and their adjacency list, and edge weight
		void print();

		//segements the graph by putting each pixel in a component and merges pixels
		//with similar intensity thus creating sub-regions of the graphs
		void Segment();
};

#include "Graph.cpp"

#endif // GRAPH_PRJ_H
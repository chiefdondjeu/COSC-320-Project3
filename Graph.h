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
#include<queue> 
#include<iostream>
#include<algorithm>

template <class T>
class Graph
{
	private:

		struct Pixel
		{
			T data;
			double weight;	//difference in intensity between two pixels

			Pixel(T d, double w)
			{
				data = d;
				weight = w;
			}
		};

		std::map<T,std::vector<Pixel> > V; 	//pixels and their edges with other pixels
		std::map<T,double> W;	//pixels and their intensity

		//int vertcount, edgecount;

		std::map< double,std::pair<T,T> > pi;

		//returns a positive difference of two number
		double difference(double&,double&);

		//help prints content stored in vector
		void printVect(std::vector<Pixel>&);

		bool isPresent(std::vector<T>,T);

		bool isDisjoint(std::vector<std::vector<T> >,T,T);

		double internal_size(std::vector<std::vector<T> >, T);

		void merge(std::vector<std::vector<T> >&, T,T);


	public:

		Graph();

		~Graph();

		//add a pixel
		void addVertex(T,double);

		//add edge between 2 pixels
		void addEdge(T,T);

		//prints all pixels along with their relative information
		void print();

		void Segment();	//TODO: need to figure out return type
};

/*	DEFINITIONS */

template <class T>
Graph<T>::Graph()//: vertcount(0), edgecount(0)
{}

template <class T>
Graph<T>::~Graph()
{}

template <class T>
//returns a positive difference of two number
double Graph<T>::difference(double& a, double& b)
{
	if((a-b) < 0)
		return -(a-b);
	else return (a-b);
}

template <class T>
void Graph<T>::addVertex(T v, double w)
{
	if(V.find(v) == V.end())
	{
		std::vector<Pixel> vect;
		V[v] = vect;
		W[v] = w;

		//vertcount++;
	}
}

template <class T>
void Graph<T>::addEdge(T u, T v)	//undirected edge
{
	//pixel have already been added and no self edges
	if(V.find(u) != V.end() && V.find(v) != V.end() && u != v)
	{
		typename std::map<T,double>::iterator iteru = W.find(u);
		typename std::map<T,double>::iterator iterv = W.find(v);

		V[u].push_back(Pixel(v,difference(iteru->second,iterv->second)));
		V[v].push_back(Pixel(u,difference(iteru->second,iterv->second)));

		std::pair<T,T> p = std::make_pair(u,v);
		pi[difference(iteru->second,iterv->second)] = p;

		//edgecount++;
	}
}

template <class T>
//help prints content stored in vector
void Graph<T>::printVect(std::vector<Pixel>& vect)
{
	for(int i = 0; i < vect.size(); i++)
	{
		std::cout << vect.at(i).data << "(" << vect.at(i).weight << ") ";
	}
}

template <class T>
void Graph<T>::print()
{
	std::cout << "========================================" << std::endl;
	std::cout << "\t\tGraph" << std::endl;
	typename std::map<T, std::vector<Pixel> >::iterator iter;
	typename std::map<T,double>::iterator iterW;
	std::cout << "========================================";
	for(iter = V.begin(), iterW = W.begin(); iter != V.end(); iter++,iterW++)
	{
		std::cout << "\nVertex: " << iter->first << "-" << iterW->second << std::endl;
		std::cout << "Adjacencies: ";
		printVect(iter->second);
		std::cout << std::endl;
	}
}

template <class T>
bool Graph<T>::isPresent(std::vector<T> vect, T x)
{
	for(int i = 0; i < vect.size(); i++)
	{
		if(vect.at(i) == x)
			return true;
	}
	return false;
}

template <class T>
bool Graph<T>::isDisjoint(std::vector<std::vector<T> >S, T x,T y)
{
	for(int i = 0; i < S.size(); i++)
	{
		if(!isPresent(S.at(i),x))
		{	
			if(!isPresent(S.at(i),y))
				return true;
		}
	}
	return false;
}

//returns the internal weight of a component
template <class T>
double Graph<T>::internal_size(std::vector<std::vector<T> >S, T x)
{
	int sum = 0;
	for(int i = 0; i < S.size(); i++)
	{
		if(isPresent(S.at(i),x))
		{
			for(int j = 0; j < S.at(i).size(); j++)
			{
				for(auto l = W.begin(); l != W.end(); l++)
				{
					if(l->first == S.at(i).at(j))
						sum += l->second;
				}
			}
		}
	}
	return sum;
}

template <class T>
void Graph<T>::merge(std::vector<std::vector<T> >& S, T x,T y)
{	
	//search
	int merge_index, del_index;
	for(int i = 0; i < S.size(); i++)
	{	
		if(isPresent(S.at(i),x))
			merge_index = i;

		if(isPresent(S.at(i),y))
			del_index = i;
	}

	//copy
	std::vector<T> tmp = S.at(del_index);;

	//delete
	S.at(del_index).clear();

	//merge
	for(int i = 0; i < tmp.size(); i++)
		S.at(merge_index).push_back(tmp.at(i));

	//for(int i = 0; i < S.at(merge_index).size(); i++)
	//	std::cout << S.at(merge_index).at(i) << " ";
	//std::cout << std::endl;
}


template <class T>
void Graph<T>::Segment()
{
	/*for(auto i = pi.begin(); i != pi.end(); i++)
		std::cout << i->first << " " << i->second.first << "," << i->second.second << std::endl;*/

	//step 1
	//sort E into pi, and sort non-decreasing order

	//step 2
	// each vertex is its own component
	std::vector<std::vector<T> > S;
	std::vector<T> tmp;
	for(auto i = W.begin(); i != W.end(); i++)
	{
		tmp.push_back(i->first);
		S.push_back(tmp);
		tmp.clear();
	}

	//step 3 & 4
	for(auto q = pi.begin(); q != pi.end(); q++)
	{
		if(isDisjoint(S,q->second.first,q->second.second) && q->first < internal_size(S,q->second.first) && q->first < internal_size(S,q->second.second))
		{
			merge(S,q->second.first,q->second.second);
		}
	}

	//step 5
	std::cout << "\n========================================\n";
	std::cout << "\tSegmentation Result";
	std::cout << "\n========================================\n";
	for(int i = 0; i < S.size(); i++)
	{
		if(S.at(i).size() != 0)
		{
			std::cout << "Region " << i+1 << ": ";
			for(int j = 0; j < S.at(i).size(); j++)
				std::cout << S.at(i).at(j) << " ";
			std::cout << "\n\n";
		}
	}
}

#endif // GRAPH_PRJ_H
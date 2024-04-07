#include "Dijkstra.h"
#include <iostream>


using namespace std;

Dijkstra::Dijkstra()
{

}

Dijkstra::~Dijkstra()
{
	
}


int miniDistance(int dist[], bool prev[])
{
	int min = inf;
	int index;

	for (int i = 0; i < 7; i++)
	{
		if (prev[i] == false && dist[i] <= min)
		{
			min = dist[i];
			index = i;


		}
	}
	//cout << index << endl;

	return index;
}

void Dijkstra::findPath(int graph[7][7], int origin, int endPos)
{

	int nVertices = 7;

	int dist[7];
	bool prev[7];

	for (int i = 0; i < 7; i++)
	{

		dist[i] = inf;
		prev[i] = false;

	}

	dist[origin] = 0;

	vector<int> parents(nVertices);

	parents[origin] = NO_PARENT;


	for (int i = 0; i < 7; i++)
	{
		int m = miniDistance(dist, prev); // vertex not yet included.
		prev[m] = true;// m with minimum distance included in prev.
		for (int i = 0; i < 7; i++)
		{
			//cout << "i = " << i << " m = " << m << " prev[i] = " << prev[i] << " graph[m][i] = " << graph[m][i] << " dist[m] = " << dist[m] << " dist[m] + graph[m][i] = " << dist[m] + graph[m][i] << " dist[i] = " << dist[i] << endl;
			// Updating the minimum distance for the particular node.
			if (prev[i] == false && graph[m][i] != inf && dist[m] != inf && dist[m] + graph[m][i] < dist[i])
			{
				parents[i] = m;
				dist[i] = dist[m] + graph[m][i];
				
				//cout << "dist[i] = dist[m] + graph[m][i] = " << dist[i]  << endl;

			}

		}
	}

	char strOrigin = 65 + origin;
	char endOrigin = 65 + endPos;

	//cout << "Minimum cost from " << strOrigin << "\tTo " << endOrigin << endl;
	for (int i = 0; i < 7; i++)
	{ //Printing
		char str = 65 + i; // Ascii values for pritning A,B,C..

		if (i == endPos)
		{
			cout << "Minimum cost from " << strOrigin << " To " << endOrigin << " is " << dist[i] << endl;
			printPath(i, parents, endPos);
			//cout << dist[i] << "\t\t\t\t " << str  << endl;
		}
		
	}

}

void Dijkstra::printPath(int currentVertex, vector<int> parents, int endPos)
{

	// Base case : Source node has
	// been processed
	if (currentVertex == NO_PARENT) {
		return;
	}
	printPath(parents[currentVertex], parents, endPos);
	char str = 65 + currentVertex;

	cout << str;

	if(currentVertex != endPos )
		cout << "->";

}

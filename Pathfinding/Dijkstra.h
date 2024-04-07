#pragma once

#include <vector>
#include <limits>
#define inf std::numeric_limits<int>::max()

using namespace std;

class Dijkstra
{

public:

	Dijkstra();
	~Dijkstra();
	void findPath(int graph[7][7], int origin, int endPos);
	void printPath(int currentVertex, vector<int> parents, int endPos);
	int NO_PARENT = -1;
	

	int graph[7][7] = {
						0, 10, 15, inf, 30, inf, inf,
						inf, 0, inf, inf, inf, 57, inf,
						15, inf, 0, 16, inf, inf, 52,
						inf, inf, 13, 0, inf, inf, inf,
						30, inf, inf, inf, 0, 11, 34,
						inf, 49, inf, inf, 12, 0, inf,
						inf, inf, 63, inf, 35, inf, 0 };

	
	/*int graph[7][7] = { 0, 10, 15, 0, 30, 0, 0,
						0, 0, 0, 0, 0, 57, 0,
						15, 0, 0, 16, 0, 0, 52,
						0, 0, 13, 0, 0, 0, 0,
						30, 0, 0, 0, 0, 11, 34,
						0, 49, 0, 0, 12, 0, 0,
						0, 0, 63, 0, 35, 0, 0 };*/



private:
	
	
};


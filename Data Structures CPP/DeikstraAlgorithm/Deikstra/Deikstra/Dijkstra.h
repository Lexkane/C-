#include <stdio.h>
#include <limits.h>
#include <iostream>

// число вершин графа
#define V 9


int minDistance(int dist[], bool sptSet[])
{
	// мінімальне значення
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// друкуємо масив

void printSolution(int dist[], int n)
{
std::cout << ("Vertex  and Distance from Source\n") <<std::endl;
	for (int i = 0; i < V; i++) {
		std::cout << "Vertex " << i << " Distance from Source" << dist[i] <<std::endl;
	}
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V];     
					 

	bool sptSet[V]; // sptSet[i] буде відображати чи включається вершина в фінальний обхід

	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// перша вершина до себе має 0 відстань
	dist[src] = 0;

	// пошук шляху
	for (int count = 0; count < V - 1; count++)
	{
		//Беремо вершину з мінімальною відстанню з вершин які ще не були оброблені
		int u = minDistance(dist, sptSet);

		// помічаємо обрану вершину
		sptSet[u] = true;

		for (int v = 0; v < V; v++)

		
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// друк
	printSolution(dist, V);
}
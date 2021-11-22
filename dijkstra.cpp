#include <iostream>
using namespace std;

#define V 9
char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'u', 'v'};

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void dijkstra(int AdjacencyMatrix[V][V], int src)
{
	int dist[V]; 

	// sptSet[i] will be true if vertex i is included in shortest
	bool sptSet[V]; 
	
	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && AdjacencyMatrix[u][v] && dist[u] != INT_MAX && dist[u] + AdjacencyMatrix[u][v] < dist[v])
				dist[v] = dist[u] + AdjacencyMatrix[u][v];
	}
	
	cout <<"\nVertex \t Distance from Source(" << vertices[src] <<")" <<endl;
	for (int i = 0; i < V; i++)
		cout << vertices[i] << " \t\t"<<dist[i]<< endl;

}

int main()
{
	cout<<" ----- ANMOL 19BCE0891 ----- \n\n";
	
	int AdjacencyMatrix[V][V] = { 
//						{ a, b, c, d, e, f, g, u, v}
						{ 0, 4, 0, 0, 0, 0, 1, 2, 0 },
						{ 4, 0, 2, 0, 0, 0, 5, 0, 0 },
						{ 0, 2, 0, 0, 6, 4, 0, 0, 2 },
						{ 0, 0, 0, 0, 2, 0, 0, 3, 0 },
						{ 0, 0, 6, 2, 0, 3, 1, 0, 0 },
						{ 0, 0, 4, 0, 3, 0, 3, 0, 5 },
						{ 1, 5, 0, 0, 1, 3, 00, 1, 0 },
						{ 2, 0, 0, 3, 0, 0, 1, 0, 0 },
						{ 0, 0, 2, 0, 0, 5, 0, 0, 0 } 
					};
	
	cout<<"Enter src index ( { a, b, c, d, e, f, g, u, v} ) : ";
	int src;
	cin>>src;
	
	dijkstra(AdjacencyMatrix, src);
	
}



#include <bits/stdc++.h>
#include<iostream>
#include <list>

using namespace std;

vector<char> vname;

class Graph
{
	int V; 

	list<int> *adj;
public:
	Graph(int V); 

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		s = queue.front();
		cout << vname[s]<< " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int getIndex(vector<char> v, char K)
{
    auto it = find(v.begin(), v.end(), K);
 
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
}

int main()
{
	cout<<" --- ANMOL 19BCE0891 --- \n\n";
	
	int v,e;
	cout<<"Enter number of vertices : ";
	cin>>v;
	
	cout<<"Enter vertices name : ";
	for(int i=0; i<v; i++){
		char a;
		cin>>a;
		vname.push_back(a);
	}
	
	cout<<"\nEnter number of Edges : ";
	cin>>e;
	
	Graph g(v);
	cout<<"Enter name of start and end of Edges : "<<endl;

	for(int i=0; i<e; i++){
		char ch_str, ch_end;
		cin>>ch_str>>ch_end;
		
		int str = getIndex(vname, ch_str);
		int end = getIndex(vname, ch_end);		
		
		
		g.addEdge(str, end);
	}
	
	char src;
	cout<<"Enter the source vertex :";
	cin>>src;

	cout << "\nBreadth First Traversal from " << src <<endl;
	g.BFS(getIndex(vname, src));

	return 0;
}


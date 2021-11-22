#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<char> vname;
class Graph {
    void DFSUtil(int v);
  
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS();
};
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
  
void Graph::DFSUtil(int v)
{
    visited[v] = true;
    cout << vname[v]<< " ";
  
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}

void Graph::DFS()
{
    for (auto i:adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
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
	
	
	Graph g;
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
	
	cout << "\n Depth First Traversal from "<< src <<endl;
	g.DFS();

	return 0;
}


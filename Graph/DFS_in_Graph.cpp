// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// function to add an edge to graph
	void addAdj(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver code
int main()
{   int n,e;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    Graph g;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addAdj(u,v);
    }
    cout<<"Enter the value of node to start DFS: "<<endl;
    
    int start_node;
    cin>>start_node;
	  g.DFS(start_node);

	return 0;
}

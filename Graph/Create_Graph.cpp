// Implementation of Graph by adjacency matrix
#include <iostream>
using namespace std;

int main()
{
	// n is the number of vertices
	// m is the number of edges
	int n, m;
	cin >> n >> m ;
	int adjMat[n + 1][n + 1];
	for(int i = 0; i < m; i++){
		int u , v ;
		cin >> u >> v ;
		adjMat[u][v] = 1 ;
		adjMat[v][u] = 1 ;
	}
	
	
	return 0;
}

// Implementation of Graph by adjacency list
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph{
  public: 
  unordered_map<int,list<int>> adj;
  
  void addEdge(int u, int v, bool direction){
    adj[u].push_back(v);
    if(direction==0){
      adj[v].push_back(u);
    }
  }
  
  void printAdjList(){
    for(auto i:adj){
      cout<<i.first<<"->";
      for(auto j:i.second){
        cout<<j<<",";
      }
      cout<<endl;
    }
  }
  
};

int main(){
  int n;
  cout<<"Enter the number of nodes"<<endl;
  cin>>n;
  
  int m;
  cout<<"Enter the number of edges"<<endl;
  cin>>m;
  
  graph g;
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v,0);
  }
  g.printAdjList();
  return 0;
}
/* Input
Enter the number of nodes
5
Enter the number of edges
6
0 1
1 2 
2 3
3 1 
3 4
0 4
*/
/* 
Output
4->3,0,
3->2,1,4,
2->1,3,
1->0,2,3,
0->1,4,
*/

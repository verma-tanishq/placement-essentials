#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>

using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addAdj(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void BFS(int start_node,int m){
        queue<int> q;
        q.push(start_node);
        
        vector<bool> visited;
        visited.resize(m,false);
        
        visited[start_node] = true;
        
        //traverse all componenets of a graph
        while(!q.empty()){
            int frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }cout<<endl;
        }
    }
};

int main(){
    int n,e;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    Graph g;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addAdj(u,v,0);
    }

    //Printing Adjacent List
    g.printAdjList();
    

    cout<<"Implementation of BFS in graph"<<endl;
    cout<<"Enter the value of node to start from: "<<endl;
    
    int start_node;
    cin>>start_node;
    g.BFS(start_node,e);

    return 0;
}

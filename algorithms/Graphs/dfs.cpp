#include <bits/stdc++.h>
using namespace std;

bool vis[1000];

void dfs_iterative(vector <int> adj[],int s){
    stack <int> st;
    st.push(s);
    vis[s]=true;
    while(!st.empty()){
        int v=st.top();
        st.pop();
        for(int i=0;i<adj[v].size();i++){
            if(vis[adj[v][i]]==false){
                st.push(adj[v][i]);
                vis[adj[v][i]]=true;
            }
        }
    }

}


void dfs_recursive(vector<int> adj[],int s){
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++){
        if(vis[adj[s][i]]==false)
            dfs_recursive(adj,adj[s][i]);
    }
}

void initialize() {
        for(int i = 0;i < 10;++i)
         vis[i] = false;
    }


int main(){
    
    int nodes, edges, x, y, connectedComponents = 0;
        cin >> nodes;                       //Number of nodes
        cin >> edges;         
        vector <int> adj[nodes];              //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;     
     //Undirected Graph 
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        initialize();                           //Initialize all nodes as not visited

        for(int i = 1;i <= nodes;++i) {
         if(vis[i] == false)     {
             dfs_recursive(adj,i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
}
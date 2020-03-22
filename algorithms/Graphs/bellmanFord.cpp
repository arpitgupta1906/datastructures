#include <bits/stdc++.h>
using namespace std;

int dis[1000];
vector <int> v[1002];

void bellmanford(int nodes,int edges){
    for(int i=0;i<nodes;i++){
        dis[i]=2e4;
    }

    dis[0]=0;
    for(int i=0;i<nodes-1;i++){
        for(int j=0;j<edges;j++){
            if(dis[v[j][0]]+v[j][2]< dis[v[j][1]]){
                dis[v[j][i]]=dis[v[j][0]]+v[j][2];
            }
        }
    }

    for(int i=0;i<edges;i++){
        int x=v[i][0];
        int y=v[i][1];
        int weight=v[i][2];
        if(dis[x]!=2e4 and dis[x]+weight<dis[y]){
            cout<<"Graph contains negative cycle"<<endl;
            break;
        }
    }
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int from,next,weight;
        scanf("%d%d%d",&from,&next,&weight);
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
    }
    bellmanford(nodes,edges);
    return 0;
}
#include<iostream>

using namespace std;
int V;
int graph[20][20],parent[20];
int min_cost=0;

void krus(){
  int mini,ver,a,u,b,v;
  for(ver=0;ver<=V;ver++){
    mini=999;
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        if(graph[i][j]<mini){
          mini=graph[i][j];
          a=u=i;
          b=v=j;
        }
      }
    }
    while(parent[u]!=-1)
      u=parent[u];
    while(parent[v]!=-1)
      v=parent[v];
    if(u!=v){
      cout<<"Edge "<<a<<" -> "<<b<<" = "<<mini<<"\n";
      min_cost+= mini;
      parent[v]=u;
    }
      graph[a][b]=graph[b][a]=999;
  }

}
int main(){
  cout<<"Enter the vertices\n";
  cin>>V;
  cout<<"Adjacency matrix\n";
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cin>>graph[i][j];
      if(graph[i][j]==0)
        graph[i][j]=999;
    }
  }
  for(int i=0;i<V;i++){
    parent[i]=-1;
  }
  cout<<"End of matrix\n";
  krus();
  return 0;
}

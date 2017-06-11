#include<iostream>
using namespace std;

int V;
int graph[20][20],parent[20],key[20],discovered[20];

void print(){
  for(int i=0;i<V;i++){
    cout<<parent[i]<<" -> "<<i<<" = "<<key[i]<<"\n";
  }
}
int minindex(){
  int mini=999,j;
  for(int i=0;i<V;i++){
    if(key[i]<mini && discovered[i]!=1){
      mini=key[i];
      j=i;
    }
  }
  return j;
}

void prims(){
  int mindex;
  for(int i=0;i<V;i++){
    discovered[i]=0;
    key[i]=999;
  }
  parent[0]=-1;
  key[0]=0;

  for(int i=0;i<V-1;i++){
    mindex=minindex();
    discovered[mindex]=1;
    for(int j=0;j<V;j++){
      if(key[j]>graph[mindex][j] && discovered[j]!=1){
        key[j]=graph[mindex][j];
        parent[j]=mindex;
      }
    }
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
  prims();
  print();
  return 0;
}

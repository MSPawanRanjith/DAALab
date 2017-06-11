#include<iostream>
using namespace std;

int graph[20][20];
int V;
void wars(){
  int i,j,k;
  for(k=0;k<V;k++){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++){
        graph[i][j]=graph[i][j] || (graph[i][k]&& graph[k][j]);
      }
    }
  }
}

int main(){
  cin>>V;
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cin>>graph[i][j];
    }
  }
  wars();
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cout<<graph[i][j]<<"\t";
    }
    cout<<endl;
  }
  return 0;
}

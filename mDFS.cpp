#include<iostream>
#include<list>
using namespace std;

int graph[20][20];
int V,sv;
int discovered[20];
list <int> stack;

void depth(int node){
  int i=0;
  while(i<V){
    if(graph[node][i]!=0 && discovered[i]==0){
      stack.push_front(i);
      discovered[i]=1;
      depth(i);
    }
    i++;
  }
  cout<<stack.front()<<" ,"<<"\n";
  stack.pop_front();
  return;
}
void DFS(){
  int ver;
  discovered[sv]=1;
  stack.push_front(sv);
  ver=stack.front();
  depth(ver);
}
int main(){

      int i,j;
      cout<<"Enter the number of vertices: ";
      cin>>V;
      cout<<"\nEnter the Matrix: \n";
      for(i=0;i<V;i++)
      {
          for(j=0;j<V;j++)
          {
              cin>>graph[i][j];
          }
      }
      for(i=0;i<V;i++)
          discovered[i]=0;
      cout<<"\nEnter the start vertex";
      cin>>sv;
      cout<<"\n\nDFS starting from: "<<sv<<" is:";
      DFS();
      return 0;
}

#include<iostream>
#include<list>
using namespace std;

int graph[20][20];
int discovered[20];
int V,sv;

void BFS(){
  int i, ver;
  discovered[sv]=1;
  list <int> queue;
  queue.push_back(sv);
  while(!queue.empty()){
    ver = queue.front();

    for(int i=0;i<V;i++){
      if(graph[ver][i]!=0 && discovered[i]==0){
        queue.push_back(i);
        discovered[i]=1;
      }
    }
    cout<<ver<<" , "<<"\t";
    queue.pop_front();
  }
}
int main(int argc, char const *argv[]) {
  cout<<"Number of vertices \n";
  cin>>V;
  cout<<"Enter the matrix \n";
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cin>>graph[i][j];
    }
  }
  for(int i=0;i<V;i++)
      discovered[i]=0;
  cout<<"Enter the strart vertices \n";
  cin>>sv;
  cout<<sv<<"\t";
  BFS();
  return 0;
}

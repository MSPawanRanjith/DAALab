#include<iostream>
using namespace std;

int V,sv;
int key[20],parent[20],discovered[20];
int graph[20][20];

void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);
    cout<<j<<"<-";
}
void print(){
  for(int i=1;i<V;i++){
    cout<<sv<<" - "<<i<<"\t"<<key[i]<<"\n ";
    cout<<"path :\n";
    printPath(parent,i);
  }
}

int mini(){
  int mini=999,j=0;
  for(int i=0;i<V;i++){
    if(key[i]<mini && discovered[i]!=1){
      mini=key[i];
      j=i;
    }
  }
  return j;
}
void djk(){
  int mindex,wt;
  for(int i=0;i<V;i++){
    discovered[i]=0;
    key[i]=999;
  }
  parent[sv]=-1;
  key[sv]=0;

  for(int i=0;i<V-1;i++){
    mindex=mini();
    discovered[mindex]=1;

    for(int j=0;j<V;j++){
      wt=graph[mindex][j]+key[mindex];
      if(key[j]>wt && discovered[j]!=1){
        key[j]=wt;
        parent[j]=mindex;
      }
    }
  }
}
int main(){
  int k;
  cout<<"Enter the size of the graph :";
  cin>>V;
  for(int i=0;i<V;i++)
  {
      for(int j=0;j<V;j++)
      {
          cin>>k;
          if(k==0)
              k=999;
          graph[i][j]=k;
      }
  }
  cout<<"enter the start vertex : ";
  cin>>sv;
  djk();
  print();
  return 0;
}

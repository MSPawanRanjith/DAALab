#include<iostream>
using namespace std;

int graph[20][20];
int parents[20],key[20],discovered[20];
int V,sv;

void printPath(int parents[],int j){
  if(parents[j]==-1)
    return;
  printPath(parents,parents[j]);
  cout<<j<<" <- ";

}
void print(){
  for(int i=1;i<V;i++){
    cout <"\n";
    cout<<sv<<" - "<<i<<"\t"<<key[i]<<"\n";
    cout<<"path ";
    printPath(parents,i);
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

void djk(){
  int mindex,wt;
  for(int i=0;i<V;i++){
    discovered[i]=0;
    key[i]=999;
  }
  parents[sv]=-1;
  key[sv]=0;

  for(int i=0;i<V-1;i++){
    mindex=minindex();
    discovered[mindex]=1;

    for(int j=0;j<V;j++){
      wt=graph[mindex][j]+key[mindex];
      if(key[j]>wt && discovered[j]!=1){
        key[j]=wt;
        parents[j]=mindex;
      }
    }
  }
}
int main(){
  int i;
  cout<<"Enter the total vertices\n";
  cin>>V;
  cout<<"Start vertix\n";
  cin>>sv;
  for(i=0;i<V;i++){
    for(int j=0;j<V;j++){
      cin>>graph[i][j];
      if(graph[i][j]==0){
        graph[i][j]=999;
      }
    }
  }

  djk();
  print();
  return 0;

}

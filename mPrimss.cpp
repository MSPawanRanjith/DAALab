#include<iostream>
using namespace std;

int graph[20][20];
int v;
int discovered[20],key[20],parents[20];

void print(){
  for(int i=0;i<v;i++){
    cout<<parents[i]<<"-"<<i<<"\t"<<key[i]<<endl;
  }
}
int minindex(){
  int mini=999,j;
  for(int i=0;i<v;i++){
    if(key[i]<mini && discovered[i]!=1){
      mini=key[i];
      j=i;
    }
  }
  return j;
}
void prims(){
  int mindex;
  for(int i=0;i<v;i++){
      discovered[i]=0;
      key[i]=999;
      //parents[i]=0;
  }
  key[0]=0;
  parents[0]=-1;

  for(int i=0;i<v-1;i++){
    mindex=minindex();
    discovered[mindex]=1;
    for(int j=0;j<v;j++){
      if(key[j]>graph[mindex][j] && discovered[j]!=1){
        key[j]=graph[mindex][j];
        parents[j]=mindex;
      }
    }

  }
}

int main(){
  int k;
  cout<<"Enter the vertices \n";
  cin>>v;
  cout<<"Matrix \n";
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      cin>>k;
      if(k==0)
        k=999;
      graph[i][j]=k;
    }
  }

  prims();
  print();
  return 0;
}

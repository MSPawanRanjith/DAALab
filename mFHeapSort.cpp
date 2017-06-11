#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std;

int h[100];

void heapify(int h[],int n){
  int heap,n1,v,k,i,j;
  n1=n;
  for(int i=n1/2;i>=1;i--){
    k=i;
    v=h[k];
    heap=0;
    while(!heap && (2*k)<=n1){
      j=2*k;
      if(j<n1){
        if(h[j]<h[j+1]){
          j=j+1;
        }
      }
      if(v>=h[j])
        heap=1;
      else{
        h[k]=h[j];
        k=j;
      }
      h[k]=v;
    }
  }
}

int main(){
  int n,size,t;
  cout<<"Enter the limit\n";
  cin>>n;
  for(int i=1;i<=n;i++){
    h[i]=rand();
  }
  double start,end,tot;
  start=clock();
  heapify(h,n);
  for(int i=n;i>=1;i--){
    t=h[1];
    h[1]=h[i];
    h[i]=t;
    size=i-1;
    heapify(h,size);
  }
  ofstream o;
  o.open("HeapSortResult.txt");
  for(int i=1;i<=n;i++){
    o<<h[i]<<"\n";
  }
  return 0;
}

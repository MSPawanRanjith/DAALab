#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

const int maxlen=30000;
int list[maxlen];
int len=0;

void merge(int p,int q, int r){
  int i=0;
  int j=p;
  int k=q+1;
  int temp[len];
  while(j<=q&&k<=r){
    if(list[j]<list[k]){
      temp[i++]=list[j++];
    }
      else
      temp[i++]=list[k++];

  }
  while(j<=q){
    temp[i++]=list[j++];
  }
  while(k<=r)
    temp[i++]=list[k++];
  for(k=p,j=0;k<=r;k++,j++){
    list[k]=temp[j];
  }
}
void mergesort(int p,int r){
  if(p<r){
    int q=(p+r)/2;
    mergesort(p,q);
    mergesort(q+1,r);
    merge(p,q,r);
  }
}
int main(){
  double start,end,tot;
  int i=0;
  for(i=0;i<maxlen;i++){
    list[i]=rand();
  }
  cout<<"#------mergeSort-------#"<<"\n";
  for(;len<=maxlen;len+=10000){
    cout<<"Length : "<<len<<"\n";
    start=clock();
    mergesort(0,len-1);
    end=clock();
    tot=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time taken is : "<<tot<<"\n";
  //  cout<<list[0]<<"\t"<<list[2]<<list[3000]<<"\n";
  }
  cout<<list[0]<<"\t"<<list[2]<<list[3000]<<"\n";
  ofstream o;
  o.open("MergeSortResult.txt");
  for(i=0;i<maxlen;i++){
    o<<list[i]<<"\n";
  }
}

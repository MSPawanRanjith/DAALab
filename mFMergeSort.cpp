#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

int list[500001];
int len=0;
const int maxlen=50000;

void merge(int p,int q,int r){
  int i=0;
  int j=p;
  int k=q+1;
  int temp[len];

  while(j<=q && k<=r){
    if(list[j]<list[k]){
      temp[i++]=list[j++];
    }
    else
      temp[i++]=list[k++];
  }

  while(j<=q)
    temp[i++]=list[j++];
  while(k<=r)
   temp[i++]=list[k++];

  for(int k=p,j=0;k<=r;k++,j++){
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
  for(int i=0;i<maxlen;i++){
    list[i]=rand();
  }
cout<<list[0]<<"\t"<<list[2]<<list[3000]<<"\n";
  for(;maxlen>=len;len+=10000){
    start=clock();
    mergesort(0,len-1);
    end=clock();
    tot=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"The time taken for "<<len<<" is : "<<tot<<" sec\n";
    cout<<list[0]<<"\t"<<list[2]<<"\t"<<list[3000]<<"\n";
  }
  cout<<list[0]<<"\t"<<list[2]<<list[3000]<<"\n";
  ofstream o;
  o.open("MergeSortResult.txt");
  for(int i=0;i<maxlen;i++){
    o<<list[i]<<"\n";
  }

  return 0;
}

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxlen=30000;
int len=0;
int list[maxlen];

void insertionSort(){
  int temp;
  for(int i=1;i<len;i++){
    for(int j=i;j>=1;j--){
      if(list[j]<list[j-1]){
        temp=list[j];
        list[j]=list[j-1];
        list[j-1]=temp;
      }
      else
        break;
    }
  }
}
int main(){
  int i=0;
  double start,end,tot;
  for(i=0;i<maxlen;i++){
    list[i]=rand();
  }
  for(;len<=maxlen;len+=10000){
    cout<<"*-----Insertion Sort-------*"<<"\n";
    cout<<"length : "<<len<<"\n";
    start=clock();
    insertionSort();
    end=clock();
    tot=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"The Time Avg : "<<tot<<"\n";

  }
  ofstream o;
  o.open("InsertionSortResult.txt");
  for(i=0;i<maxlen;i++){
    o<<list[i]<<"\n";
  }
  return 0;
}

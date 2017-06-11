#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

long int part(int list[],long int low,long int hi){
  int key=list[low];
  long int i=low;
  long int j=hi+1;
  int temp;
  int flag=1;
  while(flag){
    while(list[i]<key)
      i++;
    do{
      j--;
    }while(list[j]>key);
    if(i<j){
      temp=list[i];
      list[i]=list[j];
      list[j]=temp;
    }
    flag=0;
  }
  temp=list[low];
  list[low]=list[j];
  list[j]=temp;
  return j;
}

void quick(int list[],long int low, long int hi){
  if(low>hi){
    return;
  }
  long int key=part(list,low,hi);
  quick(list,low,key-1);
  quick(list,key+1,hi);
}
int main(){
  double start,end,tot;
  const int maxlen=30000;
  int len=0;
  int list[maxlen];

  int i=0;
  for(i=0;i<maxlen;i++){
    list[i]=rand();
  }

  cout<<"#----------QuickSort--------#"<<endl;
  for(;len<=maxlen;len+=10000){
    cout<<"Length : "<<len<<"\n";
    start=clock();
    quick(list,0,len);
    end=clock();
    tot=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time taken is "<<tot<<"\n";
  }
  ofstream o;
  o.open("QuickSortResult.txt");
  for(i=0;i<maxlen;i++){
    o<<list[i]<<"\n";
  }

}

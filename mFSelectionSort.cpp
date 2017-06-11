#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>

using namespace std;

int list[50000];
int n;
const int len=50000;

void selection(){
  int temp,mini;
  for(int i=0;i<n-1;i++){
    mini=i;
    for(int j=i+1;j<n;j++){
      if(list[mini]>list[j]){
        mini=j;
      }
    }

    if(mini!=i){
      temp=list[i];
      list[i]=list[mini];
      list[mini]=temp;
    }
  }
}
int main(){
  n=0;
  double start,tot,end;
  for(int i=0;i<len;i++){
    list[i]=rand();
  }

  for(;len>=n;n+=10000){
    start=clock();
    selection();
    end=clock();
    tot=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"The time taken for "<<n<<" is : "<<tot<<" sec\n";
  }
  ofstream o;
  o.open("selectionSortResult.txt");
  for(int i=0;i<len;i++){
    o<<list[i]<<"\n";
  }
  return 0;
}

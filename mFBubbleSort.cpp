#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

int list[50000];
int n;
const int len=50000;

void bubble(){
  int temp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(list[j]>list[j+1]){
        temp=list[j];
        list[j]=list[j+1];
        list[j+1]=temp;
      }
    }
  }
}

int main(){
  n=0;
  double tot,end,start;
  for(int i=0;i<len;i++){
    list[i]=rand();
  }
  for(;len>=n;n+=10000){
  start=clock();
  bubble();
  end=clock();
  tot=(double)(end-start)/CLOCKS_PER_SEC;
  cout<<"The tot time for "<<n<<" is "<<tot<<"\n";
}
  ofstream o;
  o.open("bubbleSortResult.txt");
  for(int i=0;i<len;i++){
    o<<list[i]<<"\n";
  }
  return 0;
}

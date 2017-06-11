#include <iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>
using namespace std;
int temp;
int part(int arr[],int low,int high){
  int pivot=arr[high];
  int i=low-1;

  for(int j=low;j<=high-1;j++){
    if(arr[j]<=pivot){
      i++;
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  }
  temp=arr[i+1];
  arr[i+1]=arr[high];
  arr[high]=temp;
  return i+1;
}
void qs(int arr[],int low,int high){
  if(low<high){
    int pi=part(arr,low,high);
    qs(arr,low,pi-1);
    qs(arr,pi+1,high);
  }
}

int main()
{
    clock_t start,end;
    long int i;
    double tot;
    const long int max_length=50000;
    int list[50000];
    for(int i=0;i<max_length;i++)
    {
            list[i]=rand();
    }

    for(i=0;i<max_length;i+=10000)
    {

        start=clock();
        qs(list,0,i);
        end=clock();
        tot=(double)(end-start)/CLOCKS_PER_SEC;
        cout<<"The total time for "<<i<<" is : "<<tot<<" sec\n";
      //  qs(list,0,i);

    }
    ofstream o;
    o.open("QuickSortResult.txt");
    for(int i=0;i<max_length;i++){
      o<<list[i]<<"\n";
    }
    return 0;
}

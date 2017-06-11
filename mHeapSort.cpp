#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int h[50];
void heapify(int h[],int n){
  int n1,heap,v,k,i,j;
  n1=n;
  for(i=n1/2;i>=1;i--){
    k=i;
    heap=0;
    v=h[k];
    while(!heap && (2*k)<=n1){
      j=2*k;
      if(j<n1){
        if(h[j]<h[j+1])
        j=j+1;
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
  int i=0;
  int n,size,t;
  double start,end,tot;
  cout<<"enter the n\n";
  cin>>n;
  for(i=0;i<n;i++){
    h[i]=rand();
    cout<<h[i]<<"  ";
  }
  cout<<"\n";
  start=clock();
  heapify(h,n);
  for(int i=n;i>=1;i--){
    t=h[1];
    h[1]=h[i];
    h[i]=t;
    size=i-1;
    heapify(h,size);
  }
  end=clock();
  tot=(double)(end-start)/CLOCKS_PER_SEC;
  cout<<"\n tot time is "<<tot<<endl;

  for(int i=0;i<n;i++)
    cout<<h[i]<<"   ";
    return 0;

}

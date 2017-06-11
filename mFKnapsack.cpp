#include<iostream>
using namespace std;

int v[20][20],p[20],w[20];

int maxi(int i,int j){
  return ((i>j)?i:j);
}

int knap(int i,int j){
  int value;
  if(v[i][j]<0){
    if(j<w[i]){
      value=knap(i-1,j);
    }
    else{
      value=maxi(knap(i-1,j),p[i]+knap(i-1,j-w[i]));
    }
    v[i][j]=value;
  }
  return v[i][j];
}
int main(){
  int n,cap;
  cout<<"number of ele\n";
  cin>>n;
  cout<<"capacity \n";
  cin>>cap;
  for(int i=1;i<=n;i++){
    cin>>p[i]>>w[i];
  }

  for(int i=0;i<=n;i++){
    for(int j=0;j<=cap;j++){
      if(i==0 || j==0){
        v[i][j]=0;
      }
      else
        v[i][j]=-1;
    }
  }

  int tot=knap(n,cap);

  int x[20]={0},k,l;
  l=cap;
  k=n;
  while(k!=0 && l!=0){
    if(v[k][l]!=v[k-1][l]){
      x[k]=1;
      l=l-w[k];
    }
    k--;
  }

  for(int i=1;i<=n;i++){
    if(x[i]==1){
      cout<<"item "<<i <<" val = "<<p[i]<<" wieght = "<<w[i]<<"\n";
    }
  }
  cout<<"tot profit "<<tot<<"\n";

  return 0;
}

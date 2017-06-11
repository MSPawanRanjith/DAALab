#include<iostream>
using namespace std;
int v[20][20],p[20],w[20];

int maxi(int a, int b){
  return ((a>b)?a:b);
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
  cout<<"The number of items \n"<<endl;
  cin>>n;
  cout<<"Profit and wieght\n"<<endl;
  for(int i=1;i<=n;i++){
    cin>>p[i]>>w[i];
  }
  cout<<"capacity of bag \n";
  cin>>cap;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=cap;j++){
      if(j==0||i==0)
        v[i][j]=0;
      else
        v[i][j]=-1;
    }
  }
  int profit=knap(n,cap);

  int k,l,x[20]={0};
  k=n;
  l=cap;
  while(k!=0 && l!=0 ){
    if(v[k][l]!=v[k-1][l]){
      x[k]=1;
      l=l-w[k];
    }
    k--;
  }
  for(int i=1;i<=n;i++){
    if(x[i]){
      cout<<i<<"th element "<<p[i]<<" profit   "<<w[i]<<"  wieght\n";
    }
  }
  cout<<"tprofit is "<<profit;
  return 0;
}

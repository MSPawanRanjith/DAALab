#include<iostream>
#include<math.h>
using namespace std;
int board[20][20],n,x[20];
int count=0;

void printsolution(){
  count ++;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<board[i][j]<<"\t";
    }
    cout<<"\n";
  }
}

int abs(int i,int j){
  int c;
  c=i-j;
  if(c<0)
  return -c;
  else
  return c;
}
int feasible(int row,int column){
  int crow;
  for(crow=0;crow<row;crow++){
    if((x[crow]==column)|| (abs(x[crow],column)== abs(row,crow)))
      return 0;

  }

  return 1;
}
void nqueens(int row){
  int i;
  if(row<n){
    for(i=0;i<n;i++){
      if(feasible(row,i)==1){
        board[row][i]=1;
        x[row]=i;

        nqueens(row+1);

        board[row][i]=0;
        x[row]=999;
      }

    }
  }
  else{
    cout<<"The solution is \n";
    printsolution();
  }
}
int main(){
  cout<<"Enter n \n";
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      board[i][j]=0;
      x[i]=999;
    }
  }

  nqueens(0);
  cout<<count<<"\n";
  return 0;

}

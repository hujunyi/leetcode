#include<iostream>
using namespace std;
int uniquePaths(int m, int n){
  int Paths[m][n];
  Paths[m-1][n-1]=1;
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      if(i==n-1&&j==m-1)  continue;
      Paths[j][i]=(j+1<=m-1 && i+1<=n-1)? Paths[j+1][i]+Paths[j][i+1] : ((j+1>m-1)?Paths[j][i+1]:Paths[j+1][i]);
    }
  }
  return Paths[0][0];
}
int main(){
  cout<<uniquePaths(2,3)<<endl;
  return 0;
}

        
  

  

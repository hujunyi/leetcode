#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minPathSum(vector<vector<int> > &grid) {
  int m=grid.size();
  if(m==0)     return 0;
  int n=grid[0].size();
  int Paths[m][n];
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(i==m-1&&j==n-1){
        Paths[i][j]=grid[i][j];
        continue;
      }
      Paths[i][j] =grid[i][j]+( (i+1<=m-1&&j+1<=n-1)? min(Paths[i+1][j],Paths[i][j+1]):((i+1>=m)? Paths[i][j+1]:Paths[i+1][j]));
    }
  }
  return Paths[0][0];

}
int minPathSum_one_dimensional_array(vector<vector<int> > &grid) {
  int m=grid.size();
  if(m==0)     return 0;
  int n=grid[0].size();
  int Paths[n];
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(i==m-1&&j==n-1){
        Paths[j]=grid[i][j];
        continue;
      }
      Paths[j] =grid[i][j]+( (i+1<=m-1&&j+1<=n-1)? min(Paths[j],Paths[j+1]):((i+1>=m)? Paths[j+1]:Paths[j]));
    }
  }
  return Paths[0];

}

int main(){
  vector<vector<int> > grid;
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  vector<int> b(2,1);
  grid.push_back(a);
  grid.push_back(b);
  cout<<minPathSum_one_dimensional_array(grid)<<endl;
  return 0;
}

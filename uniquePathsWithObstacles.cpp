#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
  int m = obstacleGrid.size();
  if(m==0)    return 0;
  int n = obstacleGrid[0].size();
  if(obstacleGrid[m-1][n-1]==1) return 0;
  int Paths[m][n];
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(i==m-1&&j==n-1){
        Paths[i][j]=1;
        continue;
      }
      if(obstacleGrid[i][j]==1){
        Paths[i][j]=0;
        continue;
      }
      Paths[i][j]=(i+1<m&&j+1<n)? (Paths[i+1][j]+Paths[i][j+1]):((i+1>=m)?Paths[i][j+1]:Paths[i+1][j]);
    }
  }
  return Paths[0][0];
}
int main(){
  vector<vector<int> > Matrix;
  vector<int> a(1,0);
  Matrix.push_back(a);
  cout<<Matrix[0][0]<<endl;
  cout<<uniquePathsWithObstacles(Matrix)<<endl;
  return 0;
}

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void buildMatrix(vector<vector<int> > &result,int col, int row,int length,int num,int target){
  //up row
  for(int i=col;i<col+length;i++){
    result[row][i]=num++;
  }
  //right col
  for(int i=row+1;i<row+length;i++){
    result[i][col+length-1]=num++;
  }
  //down row
  for(int i=col+length-2;i>=col;i--){
    result[row+length-1][i]=num++;
  }
  //left col
  for(int i=row+length-2;i>=row+1;i--){
    result[i][col]=num++;
  }
  if(num>target)
    return;
  else
    buildMatrix(result,col+1,row+1,length-2,num,target);
}
vector<vector<int> > generateMatrix(int n) {
  int target = pow(n,2); 
  vector<vector<int> > result;
  for(int i=0;i<n;i++){
    vector<int> tmp(n);
    result.push_back(tmp);
  }
  buildMatrix(result,0,0,n,1,target);
  return result;
}
void showMatrix(vector<vector<int> > matrix){
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  vector<vector<int> > result=generateMatrix(4); 
  showMatrix(result);
  return 0;
}


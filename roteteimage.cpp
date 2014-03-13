#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void printMatrix(vector<vector<int> > matrix){
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix.size();j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
void rotate1(vector<vector<int> > &matrix) {
  int length = matrix.size();
  for(int i=0;i<length-1;i++){
    for(int j=0;j<length-i;j++){
      swap(matrix[i][j],matrix[length-1-j][length-1-i]);
    }
  }
  printMatrix(matrix);
  for(int i=0;i<=(length-1)/2;i++){
    for(int j=0;j<=length-1;j++){
      swap(matrix[i][j],matrix[length-1-i][j]);
    }
  }

}
void rotate(vector<vector<int> > &matrix) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int len = matrix[0].size();  
  for(int i =0; i<len-1; i++)  
  {  
    for(int j=0;j<len-i;j++)  
    {  
      swap(matrix[i][j], matrix[len-1-j][len-1-i]);  
    }  
  }  
  printMatrix(matrix);
  for(int i =0; i<len/2; i++)  
  {  
    for(int j=0;j<len;j++)  
    {  
      swap(matrix[i][j], matrix[len-i-1][j]);  
    }  
  }  
} 

int main(){
  vector<vector<int> > matrix(3,vector<int>(3));
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;
  rotate1(matrix);
  printMatrix(matrix);
}

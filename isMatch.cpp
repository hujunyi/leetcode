#include<iostream>
#include<vector>
using namespace std;
bool isMatch(const char *s,const char *p){
  int size =(int)strlen(s)+1;
  int chars=0;
  for(int i=0;i<strlen(p);i++){
    if(p[i]!='*'&&size-1<++chars) return false;
  }
  vector<vector<bool> > matrix(2, vector<bool>(size,false));
  bool indexCol = 1;
  const char *ss;
  matrix[0][0]=true;
  while(*p){
    int indexRow = 1;
    ss = s;
    if(*p=='*'){
      //Ignore multiple *
      while(*p=='*')  p++;
      p--;
      matrix[indexCol][0] = matrix[!indexCol][0];
      //In the matrix, if the value of its  upper cell or left cell, then the values of the current cell and all its right cells must be true
      for(;indexRow<size;indexRow++){
        if(matrix[!indexCol][indexRow]||matrix[indexCol][indexRow-1]){
          while(indexRow<=size){
           matrix[indexCol][indexRow]=true;
           indexRow++;
          }
        }else
          matrix[indexCol][indexRow]=false;
      }
    }
    else{
      //the value should be equal to its diagonal upper value
      while(*ss){
        if(*p==*ss||*p=='?'){
          matrix[indexCol][indexRow]=matrix[!indexCol][indexRow-1];
        } else {
          matrix[indexCol][indexRow] = false;
        }
        matrix[indexCol][0] = false;
        ss++;
        indexRow++;
      }
    }
    p++;
    indexCol=!indexCol;
  }
  //the last row in the matrix is for '\0', so return the second last row
  return matrix[!indexCol][size-1];
}
int main(){
  char s[] = "aa";
  char p[] = "*";
  cout<<isMatch(s,p)<<endl;
  return 0;
}  
    

  

  
  

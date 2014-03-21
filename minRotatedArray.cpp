#include<iostream>
#include<vector>
using namespace std;
int minRotatedArray(vector<int> Array){
  int L=0;
  int R=Array.size()-1;
  int M;
  while(L<R){
    M = L+(R-L)/2;
    if(M==L){
      return (Array[M]>Array[R])?R:M;
    }
    if(R-L>=2&&Array[M-1]>Array[M]&&Array[M+1]>Array[M])  return M;
    if(Array[M]>Array[L]){
      L=M+1;
    }
    if(Array[M]<Array[R]){
      R=M-1;
    }
  }
  return -1;
}
int main(){
  int Array[]={7,8,9,10,11,1,2,3,4,5,6};
  vector<int> input(Array,Array+sizeof(Array)/sizeof(int));
  //cout<<sizeof(Array)<<endl;
  cout<<minRotatedArray(input);
  return 0;
}
    
    

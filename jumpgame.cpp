#include<iostream>
using namespace std;
bool canJumpDP(int A[], int n) {
  bool result[n];
  result[n-1] = true;
  for(int i=n-2;i>=0;i--){
    
    bool flag = false;
    for(int j=i+1;j<n&&j<=i+A[i];j++){
      if(result[j])
        flag=true;
    }
    result[i]=flag;
  }
  return result[0];
}
bool canJump(int A[],int n){
  int maxLen = A[0];
  for(int i=0;i<n&&i<=maxLen;i++){
    maxLen = max(A[i]+i,maxLen);
    if(maxLen>=n-1)
      return true;
  }
  return false;
}
int main(){
  int A[] = {3,2,1,0,4};
  cout<<canJump(A,5);
  cout<<endl;
  return 0;
}


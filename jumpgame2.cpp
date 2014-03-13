#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
int jump(int A[],int n){
  int start = 0;
  int end = 0;
  int count =0;
  if(n==1) return 0;
  while(end<n){
    int maxLen =0;
    count++;
    for(int i=start;i<=end;i++){
      if(A[i]+i>=n-1)
        return count;
      else
        int maxLen = max(maxLen,A[i]+i);
    }
    start = end+1;
    end = maxLen;
  } 

}



int jump1(int A[], int n) {
  Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n <= 1)
      return 0;
  const int noWay = n + 1;
  int *jumps = new int[n];
  jumps[n-1] = 0;
  for(int i = n - 2; i >= 0; -- i) {
    int lenJump = A[i];
    int minJumps = noWay;
    for(int j = i + 1; j <= i + lenJump && j < n; ++ j) {
      if(jumps[j] + 1 < minJumps)
        minJumps = jumps[j] + 1;
    }
    jumps[i] = minJumps;
  }
  return jumps[0];
}
int main(){
  int A[2]= {1,2};
  cout<<jump(A,2);
  return 0;
}
      

    

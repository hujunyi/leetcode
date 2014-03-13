#include<iostream>
#include<algorithm>
using namespace std;
int maxSubArray(int A[],int n){
  int ret=0;
  int tmp=0;
  for(int i=0;i<n;i++){
    tmp +=A[i];
    if(i==0)
      ret = A[0];
    else
      ret = max(ret,tmp); 
    if(tmp<=0)
      tmp=0;
  }
  return ret;
}
int main(){
  int A[] = {-2,1};
  cout<<maxSubArray(A,sizeof(A)/sizeof(int))<<endl;
  return 0;
}

    


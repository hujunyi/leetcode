#include<iostream>
#include<climits>
#include<vector>
using namespace std;
//int sum(int freq[],int i,int j){
//  int ret =0;
//  for(int m=i;m<=j;m++){
//    ret+=freq[m];
//  }
//  return ret;
//}
void calculateSum(int freq[],vector<vector<int> > &sum,int n){
  for(int i=0;i<n;i++){
    sum[i][i]=freq[i];
  }
 for(int j=1;j<n;j++){

  for(int i=0;i<j;i++){
    sum[i][j]+= sum[i][j-1]+freq[j];
  }
 }
}
    

int OptimalBinarySearchTree(int freq[], int n){
  int cost[n][n];
  vector<vector<int> > sum(n,vector<int>(n,0));
  calculateSum(freq,sum,n);
  for(int i=0;i<n;i++)
    cost[i][i]=freq[i];
  for(int L=2;L<=n;L++){
    for(int i=0;i<=n-L;i++){
      int j=i+L-1;
      cost[i][j]=INT_MAX;
      for(int r=i;r<=j;r++){
        int c = ((r>i)? cost[i][r-1]:0)+((r<j)? cost[r+1][j]:0)+sum[i][j];
        if(c<cost[i][j])
          cost[i][j]=c;
      }
    }
  }
  return cost[0][n-1];
}
int main()
{
  int freq[] = {34, 8, 50};
  cout<<OptimalBinarySearchTree(freq,3)<<endl;
  return 0;
}


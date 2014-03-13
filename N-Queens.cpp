#include<iostream>
#include<vector>
#include<string>
using namespace std;
void dfs(vector<vector<string> > &result,vector<string> solution,int n,int step){
  if(step==n){
    result.push_back(solution);
    return;
  }
  for(int i=0;i<n;i++){
    bool flag=true;
    for(int j=0;j<solution.size();j++){
      int position = solution[j].find("Q");
      if(position==i||(abs(j-step)==abs(position-i))) //The index of compared Q is [j][position], the index of the cnadidate is [step][i]
        flag=false;
    }
    if(flag){
      string row(n,'.'); 
      row[i]='Q';
      solution.push_back(row);
      dfs(result,solution,n,step+1);
      solution.pop_back();

    }
  }
}
      
  
vector<vector<string> > solveNQueens(int n) {
  vector<vector<string> > result;
  vector<string> solution;
  dfs(result,solution,n,0);
  return result;
}
int main(){
  vector<vector<string> > result = solveNQueens(5);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout<<result[i][j]<<endl;
    }
    cout<<"-----------------------------"<<endl;
  }
  return 0;
}



#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >permuteUnique(){
}

void dfs(vector<int> num,vector<vector<int> > &result,vector<bool> visited,vector<int> &solution,int &step){
  if(step == num.size()){
    result.push_back(solution);
    return;
  }
  for(int i=0;i<num.size();i++){
    if(!visited[i]){
      visited[i] = true;
      solution.push_back(num[i]);
      step++;
      dfs(num,result,visited,solution,step);
      solution.pop_back();
    }
  }
}

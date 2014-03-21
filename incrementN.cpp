#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void incrementN(int n,vector<vector<int> > &result, vector<int> solution,  int pre){
  if(solution.size()==n){
    result.push_back(solution);
    return;
  }
  for(int i=pre+1;i<=9;i++){
      solution.push_back(i);
      incrementN(n,result,solution,i);
      solution.pop_back();
  }
}
void showResult(vector<vector<int> > result){
  for(vector<vector<int> >::iterator i=result.begin();i!=result.end();i++){
    for(vector<int>::iterator j = (*i).begin();j!=(*i).end();j++){
      cout<<*j<<" ";
    }
    cout<<endl;
  }
  
}
vector<vector<int> > solveProblem(int n){
  vector<int> solution;
  vector<vector<int> > result;
  incrementN(n,result,solution,-1);
  return result;
}
int main(){
  vector<vector<int> > result = solveProblem(3);
  showResult(result);
}


  
  

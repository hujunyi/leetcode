#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(vector<int> &candidates,int target,int sum,int level,vector<int> intermediate,vector<vector<int> > &result){
	if(sum==target){
		result.push_back(intermediate);
		return;
	}
	if(sum>target)
			return;	
	for(int i=level;i<candidates.size();i++){	
		sum+=candidates[i];
		intermediate.push_back(candidates[i]);
		dfs(candidates,target,sum,i,intermediate,result);
		intermediate.pop_back();
		sum-=candidates[i];
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<int> intermediate;
	vector<vector<int> > result;
	dfs(candidates,target,0,0,intermediate,result);	         
	return result;
}
int main(){
	int nums[] = {2,3,6,7};
	vector<int> candidates(nums,nums+sizeof(nums)/sizeof(int));
	vector<vector<int> > result = combinationSum(candidates,7);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

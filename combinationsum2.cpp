#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(vector<int> &nums, int target, int sum,int level,vector<int> intermediate, vector<vector<int> > &result){
	if(sum==target){
		result.push_back(intermediate);
		return;
	}
	if(sum>target)
		return;
	for(int i=level;i<nums.size();i++){
		sum+= nums[i];
		intermediate.push_back(nums[i]);
		dfs(nums,target,sum,i+1,intermediate,result);
		intermediate.pop_back();
		sum-=nums[i];
		while(i<nums.size()-1&&nums[i]==nums[i+1]) i++;
	}
}
vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	sort(num.begin(),num.end());
	vector<int> intermediate;
	vector<vector<int> > result;
	dfs(num,target,0,0,intermediate,result);
	return result;
}
int main(){
	int num[] = {10,1,2,7,6,1,5};
	vector<int> nums(num,num+sizeof(num)/sizeof(int));
	vector<vector<int> > result = combinationSum2(nums,8);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

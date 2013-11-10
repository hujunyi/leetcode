#include<iostream>
#include<string>
using namespace std;
vector<string> generateParenthesis(int n)
{
	vector<string> ret;
	generator(ret,"",0,0,n);
	return ret;
}
void generator(vector<string> &ret,string solution,int l, int r,int n)
{
	if(l==n)
		ret.push_back(solution.insert(n-r,')');
		return;
	else
	{
		generator(ret,solution+'(',l+1,r,n);
		if(l>r)
			generator(ret,solution+')',l,r+1,n);
	}
}
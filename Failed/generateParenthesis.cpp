#include<set>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<string> generateParenthesis(int n) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	vector<string> ret;
	if(n==0)
	{
		string solution;
		ret.push_back(solution);
		return ret;
	}
	if(n==1)
	{
		string solution = "()";
		ret.push_back(solution);
		return ret;
	}
	else
	{
		vector<string> subret = generateParenthesis(n-1);
		set<string> count;
		for(vector<string>::iterator i= subret.begin();i!=subret.end();i++)
		{
			string solution1 = *i+"()";
			string solution2 = "()"+*i;
			string solution3 = "("+*i+")";
			if(n==4)
			{
				cout<<"solution3:"<<solution3<<endl;
			}
			count.insert(solution1);
			count.insert(solution2);
			if(n==4)
				cout<<"size before"<<count.size()<<endl;
			count.insert(solution3);
			if(n==4)
				cout<<"size after"<<count.size()<<endl;
		}
		for(set<string>::iterator j = count.begin();j!=count.end();j++)
		{
			ret.push_back(*j);
		}
		// if(n==3)
		// {
			// for(vector<string>::iterator i = ret.begin();i!=ret.end();i++)
			// {
				// cout<<*i<<" ";
			// }
			// cout<<endl;
			// cout<<"-------------------"<<endl;
		// }			
		return ret;
	}
}
int main()
{
	// vector<string> result1 = generateParenthesis(1);
	// vector<string> result2 = generateParenthesis(2);
	// vector<string> result3 = generateParenthesis(3);
	vector<string> result4 = generateParenthesis(4);
	// for(vector<string>::iterator i = result1.begin();i!=result1.end();i++)
	// {
		// cout<<*i<<" ";
	// }
	// cout<<endl;
	// for(vector<string>::iterator i = result2.begin();i!=result2.end();i++)
	// {
		// cout<<*i<<" ";
	// }
	// cout<<endl;
	// for(vector<string>::iterator i = result3.begin();i!=result3.end();i++)
	// {
		// cout<<*i<<" ";
	// }
	// cout<<endl;
	for(vector<string>::iterator i = result4.begin();i!=result4.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	
}
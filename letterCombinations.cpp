#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;
vector<string> letterCombinations(string digits) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	vector<string> ret;
	map<char,string> numtoletters;
	string nums[] = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
	for(int i=2;i<=9;i++)
	{
		char num = (char)(i+48);
		numtoletters.insert(pair<char,string>(num,nums[i-2]));	
	}
	if(digits.size()==0)
	{
		string solution;
		ret.push_back(solution);
		return ret;
	}
	else
	{
		vector<string> firstnum;
		map<char,string>::iterator tmp = numtoletters.find(digits.at(0));
		string letters = tmp->second;
		for(string::iterator j = letters.begin();j!=letters.end();j++)
		{
			string s;
			s.push_back(*j);
			firstnum.push_back(s);
		}
		if(digits.size()==1)
		{
			return firstnum;
		}
		else
		{
			vector<string> subret = letterCombinations(digits.substr(1,digits.size()-1));
			for(vector<string>::iterator i = subret.begin(); i!=subret.end();i++)
			{
				cout<<*i<<" ";
			}
			cout<<endl;
			for(vector<string>::iterator q=subret.begin();q!=subret.end();q++)
			{
				
				for(vector<string>::iterator p=firstnum.begin();p!=firstnum.end();p++)
				{
					string current = *q;
					current.insert(0,*p);
					ret.push_back(current);
				}
			}
			return ret;
		}
	}
}
int main()
{
	string input = "22";
	vector<string> output = letterCombinations(input);
	cout<<"Answer:"<<endl;
	for(vector<string>::iterator i = output.begin(); i!=output.end();i++)
	{
		cout<<*i<<endl;
	}
}
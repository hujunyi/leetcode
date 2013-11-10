#include<vector>
#include<string>
#include<iostream>
using namespace std;
string longestCommonPrefix(vector<string> &strs) {
// Note: The Solution object is instantiated only once and is reused by each test case.
	
	string ret;
	if(strs.empty())
	{
		return ret;
	}
	bool flag;
	int prefix=0;
	while(true)
	{
		flag = true;
		
		char candidate;
		if((*strs.begin()).empty())
			return ret;
		else
			if((*strs.begin()).size()<=prefix)
				return ret;
			else
				candidate = (*strs.begin()).at(prefix);
		for(vector<string>::iterator i=strs.begin();i!=strs.end();i++)
		{
			
			if((*i).size()<=prefix)
			{
				flag = false;
				break;
			}
			
			if((*i).at(prefix)!=candidate)
			{
				
				flag = false;
				break;
			}
		}
		
		if(flag)
		{
			ret.append(1,candidate);
			prefix++;
		}
		else
			break;
	}
	return ret;
}
int main()
{
	vector<string> test;
	test.push_back("a");
	cout<<longestCommonPrefix(test)<<endl;
	
	return 0;
		
}
#include<string>
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	stack<char> count;
	char tmp;
	for(string::iterator i = s.begin();i!=s.end();i++)
	{
		if(*i=='('||*i=='['||*i=='{')
			count.push(*i);
		else
		{
			if(!count.empty())
			{
				tmp = count.top();
				count.pop();
				if((tmp=='('&&*i==')')||(tmp=='['&&*i==']')||(tmp=='{'&&*i=='}'))
					continue;
				else
				{
					cout<<"ok"<<endl;
					return false;
				}
			}
			else
				return false;
		}
	}
	if(count.empty())
		return true;
	else
		return false;
}
int main()
{
	string input = "(){}[]";
	cout<<isValid(input)<<endl;
	return 0;
}
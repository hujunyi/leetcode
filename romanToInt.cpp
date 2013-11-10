#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef map<char,int>::value_type type;
int romanToInt(string s) 
{
	map<char,int> symbols;
	symbols.insert(type('I',1));
	symbols.insert(type('V',5));
	symbols.insert(type('X',10));
	symbols.insert(type('L',50));
	symbols.insert(type('C',100));
	symbols.insert(type('D',500));
	symbols.insert(type('M',1000));
	int index = s.size()-1;
	int ret =0;
	for(;index>=0;index--)
	{
		if(symbols.find(s[index-1])->second>=symbols.find(s[index])->second)
			ret+=symbols.find(s[index])->second;
		else
		{
			ret+=(symbols.find(s[index])->second)-(symbols.find(s[index-1])->second);
			index--;
		}
	}
	return ret;
}
int main()
{
	string a;
	while(cin>>a)
	{
		cout<<romanToInt(a)<<endl;
	}
	return 0;
}
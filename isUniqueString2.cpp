/*
Problem: 
Implement an algorithm to determine if a string has all unique characters. 
What if you can not use additional data structures?
Analysis:
Assume all chars in string are ASC2 characters, so we need 256 bits to represent them.
int is 32 bits, we need an int array with size 8. 8*32 = 256
*/

#include<string>
#include<memory>
using namespace std;
bool isUnique(string s)
{
	int a[8];
	memset(a,0,sizeof(a));
	for(int i = 0;i<s.size();i++)
	{
		int index = s[i]/8;
		int offset = s[i]%32;
		int shift = 1<<offset;
		if(a[index]&shift)
		{
			return false;
		}
		else
		{
			a[index]|=offset;
		}
	}
	return true;
}
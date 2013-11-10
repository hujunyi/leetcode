/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include<iostream>
using namespace std;
bool isMatch(const char *s, const char *p) 
{
    if(*p=='\0')
	{
		return *s=='\0';
	}
	if(*(p+1)!='*')
	{
		if((*p==*s)||(*p=='.'&&*s!='\0'))
			return isMatch(s+1,p+1);
		else
			return false;
	}
	else
	{
		while((*s==*p)||(*p=='.'&&*s!='\0'))
		{
			if(isMatch(s,p+2)) 
				return true;
			s++;
		}
		return isMatch(s,p+2);
	}
}
int main()
{
	char s[] = "a";
	char p[] = "a";

	cout<<isMatch(s,p);
	return 0;
}
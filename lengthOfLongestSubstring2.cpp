#include<string>
#include<memory>
#include<iostream>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	bool exists[256];
	memset(exists,false,256);
	int head,current;
	head = 0;
	current = 0;
	int length = 0;
	while(current!=s.size())
	{
		if(exists[s[current]])
		{
			length = max(length,current - head);
			head++;
			while(s[head]!=s[current])
			{
				exists[s[head]]=false;
				head++;
			}
			current++;
			
		}
		else
		{
			exists[s[current]] = true;
			current ++;
		}
	}
	length = max(length, current - head);
	return length;
}
int main()
{
	string s = "ABCDEFAAAAAAA";
	cout<<lengthOfLongestSubstring(s);
	return 0;
}
#include<iostream>
#include<string>
#include<memory>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	bool exists[256];
	map<char,int> mymap;
	int head, current; //used to record the start of the substring and the current char counted.
	head = 0;
	current = 0;
	int length = 1;
	mymap[s[head]] = head;
	while(current!=s.size())
	{

		memset(exists,false,256);
		exists[head] = true;
		if(head == current)
		{
			current++;
		}
		if(!exists[s[current]])
		{
			mymap[s[current]] = current;
			exists[s[current]] = true;
			length = max(current - head + 1, length);
			current++;
		}
		else
		{
			head = (mymap.find(s[current])->second) + 1;
			mymap.clear();
			mymap[s[head]] = head;
		}
	}
	return length;
	
}
int main()
{
	string a = "A";
	int b[100];
	memset(b,0,100);
	cout<<(int)a[0]<<endl;
	b[a[0]] = 99;
	cout<<b[a[0]]<<endl;
	return 0;
}
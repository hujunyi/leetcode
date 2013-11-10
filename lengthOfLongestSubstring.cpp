#include<iostream>
#include<string>
#include<memory>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	
	if(s.size()==0)
		return 0;
	bool exists[256];
	map<char,int> mymap;
	int head, current; //used to record the start of the substring and the current char counted.
	head = 0;
	current = 0;
	int length = 1;
	memset(exists,false,256);
	exists[s[head]] = true;
	mymap[s[head]] = head;
	while(current!=s.size())
	{
		
		if(head == current)
		{
			current++;
			if(current==s.size())
				break;
		}
		if(!exists[s[current]])
		{
			mymap[s[current]] = current;
			exists[s[current]] = true;
			length = max(current - head + 1, length);
			// if(current == 53)
			// {
				// cout<<"head:"<<head<<endl;
				// cout<<"current:"<<current<<endl;
				// cout<<"length:"<<length<<endl;
				// cout<<mymap.size()<<endl;
				// cout<<mymap.find(s[current])->second<<endl;

			// }
			current++;
			
		}
		else
		{

			int index = (mymap.find(s[current])->second) + 1;
			while(head!=index)
			{
				mymap.erase(s[head]);
				exists[s[head]] = false;
				head++;
			}
			head = index;
			mymap[s[head]] = head;
			exists[s[head]] = true;
		}
	}
	return length;
	
}
int main()
{
//wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbe    fsarcbynecdyggxxpklorellnmpapqfwkhopkmco
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	cout<<lengthOfLongestSubstring(s);
	return 0;
}
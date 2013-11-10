#include<string>
#include<memory>
using namespace std;
bool uniquestring(string s)
{
	bool exist[256];
	memset(exist,false,256);
	for(int i=0;i<s.size();i++)
	{
		if(exist[s[i]])
		{
			return false;
		}
		exist[s[i]] = true;
	}
	return true;
}
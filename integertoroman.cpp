#include<iostream>
#include<vector>
#include<string>
using namespace std;
string intToRoman(int num) 
{
    // Note: The Solution object is instantiated only once and is reused by each test case.    
	string ret;
	char s[]={'I','V','X','L','C','D','M'};
	int m = num;
	vector<char> symbol(s,s+7);
	for(int base=0;base<=6;base+=2)
	{
		int tmp = m%10;
		m/=10;
		switch(tmp)
		{
			case 1: case 2: case 3:
				ret = string(tmp,s[base])+ret;
				break;
			case 4:
				ret = string(1,s[base])+string(1,s[base+1])+ret;
				break;
			case 5: case 6: case 7: case 8:
				ret = string(1,s[base+1])+string(tmp-5,s[base])+ret;
				break;
			case 9:
				ret = string(1,s[base])+string(1,s[base+2])+ret;
				break;
			case 0:
				break;
		}
	}
	return ret;
}
        
int main()
{
	int i;
	while(cin>>i)
	{
		cout<<intToRoman(i)<<endl;
	}
	return 0;
}
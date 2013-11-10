#include<iostream>
#include<map>
#include<math.h>
#include<string>
using namespace std;
typedef map<char,int>::value_type valType;
typedef map<string,int>::value_type roman;
int intToRoman(string s) 
{
    // Note: The Solution object is instantiated only once and is reused by each test case.    
	int ret=0;
	map<char,int> symbol;
	map<string,int> romannum;
	char romansymbol[]={'I','V','X','L','C','D','M'};
	string units[]={"I","II","III","IV","V","VI","VII","VIII","IX"};
	string decades[]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	string hundreds[]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	for(int i=0;i<7;i++)
	{
		symbol.insert(valType(romansymbol[i],i));
	}
	for(int i=0;i<9;i++)
	{
		romannum.insert(roman(units[i],i+1));
		romannum.insert(roman(decades[i],i+1));
		romannum.insert(roman(hundreds[i],i+1));
	}
	
	string::iterator j=s.end()-1;
	bool flag;
	for(int base=0;base<7;base=base+2)
	{
		flag = false;
		int index=symbol.find(*j)->second;
		string tmp;
		while(index>=base&&index<=base+1)
		{
			flag = true;
			tmp.append(1,*j);
			cout<<tmp.size()<<endl;
			j--;
			if((symbol.find(*j)->second)>(symbol.find(*(j-1))->second))
			{
				tmp.append(1,*j);
				j--;
			}
			if(j==s.end())
			{
				break;
			}
			index=symbol.find(*j)->second;
		}
		if(flag)
		{
			cout<<"final:"<<tmp.size()<<endl;
			ret+=((romannum.find(tmp))->second)*pow(10,base/2);
		}
	}
	return ret;
}
int main()
{
	string a;
	while(cin>>a)
	{
		cout<<intToRoman(a);
	}

	return 0;
}
	
	
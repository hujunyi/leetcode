/*
注意转换值的溢出，与INT_MIN比较时不能把INT_MIN转化成正，因为INT_MIN的绝对值比INT_MAX大1，会溢出
*/
#include<iostream>
#include<climits>
using namespace std;

int atoi(const char *str) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	const char* m=str;
	if(m==NULL)
		return 0;
	while(*m==' ')
		m++;
	if(((int)*m<48||(int)*m>57)&&(*m!='+'&&*m!='-'))
	{
		return 0;
	}
	int ret=0;
	bool isNegative=false;
	if(*m=='-')
	{
		isNegative = true;
		m++;
	}
	if(*m=='+')
	{
		isNegative = false;
		m++;
	}
	while(true)
	{
		int i=(int)*m;
		if(i>=48&&i<=57)
		{
			if(isNegative)
			{
				if((INT_MIN+(i-48))/10>-ret)
				{
					return INT_MIN;
				}
			}
			else
			{
				if((INT_MAX-(i-48))/10<ret)
					return INT_MAX;
			}
			ret = ret*10 + i-48;
			m++;
		}
		else
		{
			break;
		}
		
	}    
	ret=isNegative?-ret:ret;
	return ret;
}
int main()
{
	char s[] = "-00134";
	cout<<atoi(s)<<endl;
	return 0;
}
#include<iostream>
using namespace std;
using namespace std;
bool isMatch(const char *s, const char *p) 
{
        // Note: The Solution object is instantiated only once and is reused by each test case.   
    if(*p=='*')
		return false;
	const char* i = p;
    while(true)
	{
        if(!*i)
		{
			
			if(*s)
			{	
				return false;
			}            
        }
		if(!*s)
		{
			return true;
		}
		else
		{
			if((*s==*i)||(*i=='.')){
				i++;
				s++;
			}
			else if(*i=='*')
			{
				const char* j=i;
				while(*j=='*')
				{
					j--;
				}
				
				if((*j==*s)||(*j=='.'))
				{
					s++;
				}
				i++;
	
			}
			else
			{
				i++;
			}
		}
    }
}
int main(){
	cout<<isMatch("ab",".*c")<<endl;
	
}
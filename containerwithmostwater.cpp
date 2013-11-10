#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxArea(vector<int> &height) 
{
    // Note: The Solution object is instantiated only once and is reused by each test case.
	vector<int>::iterator i=height.begin();
	vector<int>::iterator j=height.end()-1;
	int ret=0;
	while(i!=j)
	{
		int tmp=(j-i)*min(*i,*j);
		ret=max(tmp,ret);
		if(*i>*j)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return ret;
	
}
bool myfunction (int i,int j) { return (i>j); }
int main()
{
	int myints[] = {1,1};
	vector<int> myvector (myints, myints+2);
	cout<<maxArea(myvector)<<endl;
	
	return 0;
	
}
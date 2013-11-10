#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int> &num, int target) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int closest=*(num.begin())+*(num.begin()+1)+*(num.begin()+2);
	sort(num.begin(),num.end());
	for(vector<int>::iterator i=num.begin();i!=num.end();i++)
	{
		int current=*i;
		vector<int> rest(num);
		rest.erase(rest.begin()+(i-num.begin()));
		// cout<<*i<<":"<<endl;
		for(vector<int>::iterator j=rest.begin(),k=rest.end()-1;j<k;)
		{
			closest=abs(closest-target)>abs(*i+*j+*k-target)? *i+*j+*k:closest;
			// cout<<"i:"<<*i<<" k:"<<*k<<" j:"<<*j<<endl;
			// cout<<*i+*k+*j-target<<endl;
			// cout<<closest<<endl;
			if(*i+*j+*k<target)
			{
				j++;
			}
			else if(*i+*j+*k>target)
			{
				k--;
				
			}
			else
			{
				return *i+*j+*k;
			}
		}
	}
	return closest;
}
int main()
{
	//int a[]={-1, 2, 1, -4};
	int a[]={0, 1, 2};
	vector<int> s(a,a+3);
	cout<<threeSumClosest(s,0)<<endl;
	return 0;
}
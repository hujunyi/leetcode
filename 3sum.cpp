#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	vector<vector<int> > ret;
	sort(num.begin(),num.end());
	set<int> counter;
	bool flag;
	vector<int> tmp(num);
	for(vector<int>::iterator i=num.begin();i<num.end();i++)
	{
		tmp.erase(tmp.begin());
		if(counter.count(*i))
		{
			continue;
		}
		set<int> innercounter;
		for(vector<int>::iterator j=tmp.begin(),k=tmp.end()-1;j<k;)
		{
			
			if(*j+*k+*i>0)
			{
				if(k==tmp.begin())
					break;
				else
					k--;
			}
			else if(*j+*k+*i<0)
			{
				j++;
				if(j==tmp.end())
					break;
			}
			else
			{
				
				vector<int> solution;
				solution.push_back(*i);
				solution.push_back(*j);
				solution.push_back(*k);
				sort(solution.begin(),solution.end());
				k--;
				j++;
				if(innercounter.count(*(solution.end()-1)))
				{
					continue;
				}
				else
				{
					ret.push_back(solution);	
					innercounter.insert(*(solution.end()-1));				
				}
			}
		}
		counter.insert(*i);
	}
	return ret;
}
int main()
{
	int S[] = {0,0, 0, 0, 0, 0,0};
	vector<int> num(S,S+7);
	vector<vector<int> > result = threeSum(num);
	for(vector<vector<int> >::iterator i = result.begin();i!=result.end();i++)
	{
		for(vector<int>::iterator j=(*i).begin();j!=(*i).end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	return 0;
	
}
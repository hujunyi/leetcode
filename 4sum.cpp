#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num,int target) {
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
			
			if(*j+*k+*i>target)
			{
				if(k==tmp.begin())
					break;
				else
					k--;
			}
			else if(*j+*k+*i<target)
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
vector<vector<int> > fourSum(vector<int> &num, int target) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	set<int> counter;
	vector<vector<int> > ret;
	sort(num.begin(),num.end());
	vector<int> tmp(num);
	for(vector<int>::iterator i=num.begin();i!=num.end();i++)
	{
		 cout<<"############"<<*i<<"###############"<<endl;
		if(counter.count(*i))
		{
			tmp.erase(tmp.begin());
			continue;
		}
		else
		{
			counter.insert(*i);
			tmp.erase(tmp.begin());
			// for(vector<int>::iterator k = tmp.begin();k!=tmp.end();k++)
			// {
				// cout<<*k<<" ";
			// }
			cout<<endl;
			vector<vector<int> > three=threeSum(tmp,target-*i);
			
			// for(vector<vector<int> >::iterator k = three.begin();k!=three.end();k++)
			// {
				// for(vector<int>::iterator m=(*k).begin();m!=(*k).end();m++)
				// {
					// cout<<*m<<" ";
				// }
				// cout<<endl;
			// }
		
			if(!three.empty())
			{
				for(vector<vector<int> >::iterator j=three.begin();j!=three.end();j++)
				{
					(*j).push_back(*i);
					sort((*j).begin(),(*j).end());
					ret.push_back(*j);
				}	
			}
			else
			{
				continue;
			}
		}	
	}
	return ret;
}
int main()
{
	int S[] = {-1,-5,-5,-3,2,5,0,4};
	vector<int> num(S,S+8);
	vector<vector<int> > result = fourSum(num,-7);
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
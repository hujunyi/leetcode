#include<iostream>
#include<memory.h>
#include<math.h>
using namespace std;
#define max 10000
int t;
bool primetable[max];
bool visited[max];
void generateprimetable()
{
	memset(primetable,true,sizeof(primetable));
	for(int i = 2; i < sqrt(max); i++)
	{
		if(primetable[i])
			for(int j = i*i; j < max; j = j+i) //why i*i: i-1 or less numbers have been tested by prior loop
			{
				primetable[j] = false;
			}
	}
}
bool dfs(int n, int m, int d, int res[], int current_len) //iteration function
{
	t++;
	if(t>4000)
		return false;
	if(current_len == m -n +1) //if all numbers in the sequence have been checked
	{
		return true;
	}
	else
	{
		for(int loop=n; loop<=m; loop++)
		{
			if(!visited[loop])
			{
				res[current_len] = loop;
				if(current_len !=0) //check whether the sequence including the new element meet the requirement
				{
					bool flag = true;
					int temp = res[current_len];
					for( int j = current_len - 1; j>=0&&j>current_len - d; j--)
					{
						temp = temp + res[j];
						if(primetable[temp])
						{
							flag = false;
							break;
						}
					}
					if(flag)
					{
						visited[loop] = true;
						if( dfs(n,m,d,res,current_len+1))
							return true;
						visited[loop] = false;
					}
				}
				else
				{
					visited[loop] = true;
					if( dfs(n,m,d,res,current_len+1))
						return true;
					visited[loop] = false;
				}
			}
		}
		return false;
	}
}
int main()
{
	int n,m,d;
	generateprimetable();
	while(true)
	{
		cin>>n;
		cin>>m;
		cin>>d;
		t=0;
		if(n==0 && m==0 && d==0)
		{
			break;
		}
		else
		{
			memset(visited, false, sizeof(visited));
			int res[1000];
			if(dfs(n,m,d,res,0))
			{
				cout<<res[0];
				for(int loop=1;loop<=m-n;loop++)
				{
					cout<<","<<res[loop];
				}
				cout<<endl;
			}
			else
			{
				cout<<"No anti-prime sequence exists."<<endl;
			}
		}
	}
}
			
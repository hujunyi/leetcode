#include<iostream>
#include<string>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case. 
     int m = s1.size();
	int n = s2.size();
	if(m+n != s3.size())
		return false;
	bool subp[m+1][n+1]; //s[0][0] represents s3 is a empty string. s[i][j] represents from s3[0] to s3[i+j-1]([0][0] doens't count) can be represented by s1 and s2.

	memset(subp,false,sizeof(subp));
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0&&j==0)
			{
				subp[i][j] = true;
			}
			else if(i==0&&j!=0)
			{
				subp[i][j] = subp[i][j-1]&&(s2[j-1]==s3[j-1]);
			}
			else if(i!=0&&j==0)
			{
				subp[i][j] = subp[i-1][j]&&(s1[i-1]==s3[i-1]);
			}
			else
			{
				subp[i][j] = (subp[i][j-1]&&(s2[j-1]==s3[j+i-1]))||(subp[i-1][j]&&(s1[i-1]==s3[i+j-1]));
			}	
		}
	}
	// for(int i=0;i<m;i++)
	// {
		// for(int j=0;j<n;j++)
		// {
			// cout<<subp[i][j]<<" ";
		// }
		// cout<<endl;
	// }
	return subp[m][n];
}
int main()
{
	string s1 = "a";
	string s2 = "b";
	string s3 = "ab";
	cout<<isInterleave(s1, s2, s3)<<endl;
}
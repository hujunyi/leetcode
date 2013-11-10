#include<iostream>
#include<string>
#include<cmath>
using namespace std;
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        int batch = s.size()/(2*nRows-2);
		int remain = s.size()%(2*nRows-2);
        int columns = batch*(nRows-1);
		columns = remain>nRows ? columns + remain-nRows +1: columns + 1;
        int mod = nRows-1;
        string result[columns];
        int j=0;
        for(int i =0;i<columns;i++)
        {
            int r = i%mod;
            if(r==0)
            {
                for(int k=0;k<nRows;k++)
                {
                    result[i].push_back(s[j]);
                    j++;
                    if(j==s.size())
                        break;
                }
				
            }
            else
            {
				for(int k=0;k<nRows;k++)
				{
					if(k==nRows-1-r)
					{
						result[i].push_back(s[j]);
						j++;
					}
					else
					{
						result[i].push_back(' ');
					}
					if(j==s.size())
						break;
				}
            }
        }
        string output;
		for(int i =0;i<nRows;i++)
		{
			for(int j =0;j<columns;j++)
			{
				if(result[j][i]!=' ')
					output.push_back(result[j][i]);
			}
		}
        return output;
        
    }
int main()
{
	string s = "PAYPALISHIRING";
	cout<<convert(s,3)<<endl;
	zigSize - 2 - ir*2+1+1
	return 0;
}
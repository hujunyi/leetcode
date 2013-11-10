#include<iostream>
#include<string>
#include<cmath>
using namespace std;
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.  
		if(nRows <= 1) return s;
		int zigSize = nRows*2-2;
		string result;
		for(int i =0;i<nRows;i++)
		{
			for(int base =i;base<s.size();base+=zigSize)
			{
				if(i==0||i==nRows-1)
				{
					result.push_back(s[base]);
					continue;
				}
				else
				{
					result.push_back(s[base]);
					//In each batch, the first row and last row has 1 number, and the middle rows has two numbers
					//Their difference value is zigSize minus all the numbers above them(i*2+1), and minus 1(the first number itself)
					if(base+zigSize-i*2<s.size())
						result.push_back(s[base+zigSize-i*2]);
				}
			}
		}
		return result;
        
    }
int main()
{
	string s = "PAYPALISHIRING";
	cout<<convert(s,3)<<endl;
	return 0;
}
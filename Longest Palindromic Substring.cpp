 #include<iostream>
 #include<string>
using namespace std;
string longestPalindrome(string s) 
{
        // Note: The Solution object is instantiated only once and is reused by each test case.
		bool table[1000][1000] = {false};
        for(int i=0;i<1000;i++)
        {
            table[i][i]=true;
        }
        int startchar=0;
        int length = 1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                startchar = i;
                table[i][i+1]=true;
                length = 2;
            }
        }
        for(int testlength=3;testlength<=s.size();testlength++)
        {
            for(int i=0;i<=s.size()-testlength;i++)
            {
                if(s[i]==s[i+testlength-1]&&table[i+1][i+testlength-2])
                {
                    length = testlength;
                    table[i][i+testlength-1]=true;
                    startchar=i;
                }
            }
        }
        return s.substr(startchar,length);
}
int main()
{
	string a = "aaabaaaa";
	cout<<longestPalindrome(a);
	return 0;
}
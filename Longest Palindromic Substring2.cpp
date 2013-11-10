#include<string>
using namespace std;
string longestPalindrome()
{
 string longest = s.substr(0,1);
        for(int i=0;i<s.size();i++)
        {
            string s1 = expandAroundCenter(s,i,i);
            if(s1.size()>longest.size())
            {
                longest = s1;
            }
            string s2 = expandAroundCenter(s,i,i+1);
            if(s2.size()>longest.size())
            {
                longest = s2;
            }
        }
        return longest;
}
    string expandAroundCenter(string s,int i, int j)
    {
        while(i>=0&&j<s.size()&&s[i]==s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1,j-1-i);
    }
#include<iostream>
#include<climits>
using namespace std;
bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int palindrome = 0;
        while(x!=0)
        {
            if(INT_MAX<(palindrome-x%10)/10)
            {
                return false;
            }
         
            palindrome = palindrome*10+x%10;
            x/=10;
        }
        return palindrome==x;
 
    }
int main()
{
	cout<<isPalindrome(1)<<endl;
	return 0;
}
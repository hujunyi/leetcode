#include<iostream>
using namespace std;
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        while(x!=0)
        {
            ret=ret*10 + x%10;
			if(ret>214748364)
				return ret;
            x/=10;
        }
        return ret;    
    }
	int main()
	{
		cout<<reverse(1000000003);
		return 0;
	}
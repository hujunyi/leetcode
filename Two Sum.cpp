#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
     
	
        // Note: The Solution object is instantiated only once and is reused by each test case.
		vector<int> numbers;
		numbers.push_back(5);
		numbers.push_back(75);
		numbers.push_back(25);
		vector<int> temp(numbers);
        sort(temp.begin(),temp.end());
        vector<int>::iterator i = temp.begin(); 
        vector<int>::iterator j = temp.end()-1;
		vector<int> result;
		int target = 100;
        while(i<j)
        {
            if(*i+*j==target)
            {
				break;
            }
            if(*i+*j>target)
            {
                j--;
                continue;
            }
            if(*i+*j<target)
            {
                i++;
                continue;
            }
        }
		for(int k = 0; k!=numbers.size(); k++)
		{
			if(*i==numbers[k]||*j==numbers[k])
			{
				result.push_back(k+1);
			}
		}
		cout<<result[0];
		cout<<result[1];
		return 0;
    
};
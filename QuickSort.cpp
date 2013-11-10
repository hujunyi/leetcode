#include<vector>
 #include<iostream>
 using namespace std;
void quicksort(vector<int> &numbers,int head, int tail)
{
	if(head<tail)
	{
		int pivot = numbers[head];
		int i = head;
		int j = tail;
		int temp;
		while(i<j)
		{
			while(i<j&&numbers[j]>pivot)
				j--;
			if(i<j)
			{
				numbers[i] = numbers[j];
				i++;
			}
			while(i<j&&numbers[i]<=pivot)
				i++;
			if(i<j)
			{
				numbers[j] = numbers[i];
				i--;
			}
		}
		numbers[i] = pivot;
		quicksort(numbers,head,i-1);
		quicksort(numbers,i+1,tail);
	}
}
int main()
{
	vector<int> test;
	int input;
	for(int i = 0;i < 10;i++)
	{
		cin>>input;
		test.push_back(input);
	}
	quicksort(test,0,test.size());
	for(int i=0;i<test.size();i++)
	{
		cout<<test[i];
	}
	return 0;
}

// void qsort(int s[], int l, int r)
// {
    // int i, j, x;
    // if (l < r)
    // {
        // i = l;
        // j = r;
        // x = s[i];
        // while (i < j)
        // {
            // while(i < j && s[j] > x) j--; /* 从右向左找第一个小于x的数 */
            // if(i < j) s[i++] = s[j];
            // while(i < j && s[i] < x) i++; /* 从左向右找第一个大于x的数 */
            // if(i < j) s[j--] = s[i];
        // }
        // s[i] = x;
        // qsort(s, l, i-1); /* 递归调用 */
        // qsort(s, i+1, r);
    // }
// }
// int main()
// {
	// int a[] = { 3,6,1,2,4,5,7,8,9};
	// qsort(a,0,9);
	// for(int i = 0;i<9;i++)
	// {
		// cout<<a[i];
	// }
	// return 0;
// }
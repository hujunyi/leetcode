#include<iostream>
#include<algorithm>
using namespace std;
int main() 
{
	int A[]={1,2,6,8};
	int m=4;
	int B[]={3,4,5,7};
	int n=4;
    findMedianSortedArrays(int A[], int m, int B[], int n)
		if(m+n<=4)
        {
            vector<int> newArray;
            for(int i =0;i<m;i++)
            {
                newArray.push_back(A[i]);
            }
            for(int j=0;j<n;j++)
            {
                newArray.push_back(B[j]);
            }
            sort(newArray.begin(),newArray.end());
            return newArray[newArray.size()/2];
        }
        int medianA = A[m/2];
        int medianB = B[n/2];
        if(medianA == medianB)
        {
            return medianA;
        }
        else if(medianA>medianB)
        {
            int* newA = A;
            int* newB = &B[medianB];
            return findMedianSortedArrays(newA,m/2+1,newB,n/2+1);
        }
        
}
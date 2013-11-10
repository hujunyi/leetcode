#include<iostream>
using namespace std;
#define MAX 1000
double FindMedianOfThree(double a,double b,double c)
{
	double minValue = min(a,min(b,c));
	double maxValue = max(a,max(b,c));
	return a+b+c-maxValue-minValue;
}
double FindMedianOfFour(double a,double b,double c,double d)
{
	int minValue = min (d, min (a, min (b,c) ) );
	int maxValue = max (d, max (a, max (b,c) ) );
	return (a + b + c + d - minValue - maxValue) / 2.0 ;
}
double FindMedian(int A[MAX], int m, int B[MAX], int n)
{
		
	if( m<n) //Consider the base cases for the shorter array
	{
		if(m ==1)
		{
			if(n==1)
			{
				return (A[0]+B[0])/2.0;
			}
			if(n%2==0)
			{
				return FindMedianOfThree(B[n/2],B[n/2-1],A[0]);
			}
			else
			{
				return (B[n/2]+FindMedianOfThree(B[n/2-1],B[n/2+1],A[0]))/2.0;
			}
			
		}
		if(m==2)
		{
			if(n==2)
			{
				return FindMedianOfFour(A[0],B[0],A[1],B[1]);
			}
			else if(n%2==0)
			{
				//cout<<B[n/2]<<B[n/2-1]<<min(A[0],B[n/2+1])<<max(A[1],B[n/2-2]);
				return FindMedianOfFour(B[n/2],B[n/2-1],min(A[0],B[n/2+1]),max(A[1],B[n/2-2]));
			}
			else
			{
				return FindMedianOfThree(B[n/2],max(B[n/2-1],A[1]),min(B[n/2+1],A[0]));
			}
		}
	}
	else// Consider the base cases for the shorter array
	{
		if(n==1)
		{
			if(m==1)
			{
				return (A[0]+B[0])/2.0;
			}
			if(m%2==0)
			{
				return FindMedianOfThree(A[m/2],A[m/2-1],B[0]);
			}
			else
			{
				return (A[m/2]+FindMedianOfThree(A[m/2-1],A[m/2+1],B[0]))/2.0;
			}
			
		}
		if(n==2)
		{
			if(m==2)
			{
				return FindMedianOfFour(A[0],B[0],A[1],B[1]);
			}
			else if(m%2==0)
			{
				return FindMedianOfFour(A[m/2],A[m/2-1],min(B[0],A[m/2+1]),max(B[1],A[m/2-2]));
			}
			else
			{
				return FindMedianOfThree(A[m/2],min(B[0],A[m/2+1]),max(B[1],A[m/2-1]));
			}
		}
	}
	int i = m/2;
	int j = n/2;
	int minRemove; //The removed length for each array
	if(A[i]>B[j])
	{

		if(n%2==1)
		{
			minRemove = min(m - i -1, j);
		}
		else
		{
			minRemove = min(m - i -1,j-1);
		}
		return FindMedian(A,m-minRemove,B+minRemove,n-minRemove);
	}
	else
	{
		if(m%2==1)
		{
			minRemove = min(i, n -j -1);
		}
		else
		{
			minRemove = min(i-1,n-j-1);
		}
		return FindMedian(A+minRemove,m-minRemove,B,n-minRemove);
	}
}
int main()
{
	int A[] = {1,4,5};
	int B[] = {2,3,6,7,8};
	cout<<FindMedian(A,3,B,5)<<endl;
	return 0;
}
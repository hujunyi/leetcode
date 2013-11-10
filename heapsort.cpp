#include<iostream>
using namespace std;
void heapify(int *A,int start,int end)
{
	int root = start;
	while(root*2+1<=end)
	{
		int left=root*2+1;
		int right=left+1;
		int largest=root;
		if(A[largest]<A[left])
		{
			largest=left;
		}
		if((right<=end)&&A[largest]<A[right])
		{
			largest=right;
		}
		if(largest!=root)
		{
			int tmp=A[largest];
			A[largest]=A[root];
			A[root]=tmp;
		}
		else
		{
			break;
		}
	}
	return;
}
void buildheap(int *A,int start,int end)
{
	int mid=(end-start-1)/2;
	while(mid>=start)
	{
		heapify(A,mid,end);
		mid--;
		for(int i=0;i<=5;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return;
}
void heapSort(int *A,int start,int end)
{
	buildheap(A,start,end);
	int size = end;
	while(size!=start)
	{
		int tmp=A[size];
		A[size] = A[0];
		A[0] = tmp;
		size--;
		heapify(A,start,size);
	}
	return;
}
int main()
{
	int a[] = {13,5,8,3,17,25};
	
	buildheap(a,0,5);
	heapSort(a,0,5);
	for(int i=0;i<=5;i++)
	{
		cout<<a[i]<<" ";
	}
		cout<<endl;
	
	return 0;
	
}
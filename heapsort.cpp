#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void heapsort(vector<int> &array){
  int mid = (array.size()-2)/2;
  int end = array.size()-1;
  for(int i=0;i<array.size();i++){
    //Construct the heap repeatedly
    mid = (end-1)/2;
    while(mid>=0){
      if(mid*2+1<=end){
        int left = mid*2+1;
        int right = left+1;
        int largest = mid;
        if(array[largest]<array[left])
          swap(array[largest],array[left]);
        if(right<=end&&array[largest]<array[right])
          swap(array[largest],array[right]);
      }
      mid--;
    }
    //Put the root to the end of the arry and reconstruct the heap 
    swap(array.front(),array[end]);
    end--;
  }
}
int main()
{
	int a[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  vector<int> array(a,a+sizeof(a)/sizeof(int));
  heapsort(array);
  for(int i=0;i<array.size();i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
	return 0;
	
}

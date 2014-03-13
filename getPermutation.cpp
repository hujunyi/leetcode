//Theet [1,2,3,…,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order,
//   We get the following sequence (ie, for n = 3):
//
//     "123"
//     "132"
//     "213"
//     "231"
//     "312"
//     "321"
//     Given n and k, return the kth permutation sequence.
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
void showSequence(vector<int> sequence){
  for(int i=0;i<sequence.size();i++){
    cout<<sequence[i];
  }
  cout<<endl;
}
//Time limits exceed
string getPermutation_tle(int n, int k) {
  vector<int> sequence;

  for(int i=1;i<=n;i++){
    sequence.push_back(i);
  }
  int count = 1;
  while(count!=k){
    for(vector<int>::reverse_iterator i=sequence.rbegin();i!=sequence.rend();i++){
      if(i+1!=sequence.rend()&& *i>*(i+1)){
        i++;
        for(vector<int>::reverse_iterator j=sequence.rbegin();j!=sequence.rend();j++){
          if(*j>*i){
            swap(*j,*i);
            reverse(sequence.rbegin(),i);
            count++;
            break;
          }
        }
        break;
      }
    }
  }
  string ret;
  for(vector<int>::reverse_iterator i=sequence.rbegin();i!=sequence.rend();i++){
    ret.insert(ret.end(),*i+'0');
  }  
  return ret;
}
//Smart way to solve this problem
string getPermutation(int n, int k) {  
  vector<int> nums(n);  
  int permCount =1;  
  for(int i =0; i< n; i++)  
  {  
    nums[i] = i+1;  
    permCount *= (i+1);        
  }  
  // change K from (1,n) to (0, n-1) to accord to index  
  k--;  
  string targetNum;  
  for(int i =0; i< n; i++)  
  {    
    permCount = permCount/ (n-i);  
    int choosed = k / permCount;  
    cout<<choosed<<endl;
    targetNum.push_back(nums[choosed] + '0');  
    //reconstruct nums since one num has been picked out 
    nums.erase(nums.begin()+choosed);  
    k = k%permCount;  
  }  
  return targetNum;  
}  
string getPermutation_myself(int n,int k){
  vector<int> nums;
  string ret;
  for(int i=1;i<=n;i++){
    nums.push_back(i);
  }
  int fact = 1;
  for(int i=1;i<=n;i++){
    fact*=i;
  }
  k--;
  for(int i=0;i<n;i++){
    fact = fact/(n-i);
    int index = k/fact;
    ret.push_back(nums[index]+'0');
    nums.erase(nums.begin()+index);
    k=k%fact;
  }
  return ret;
}








int main(){
  cout<<getPermutation_myself(3,5)<<endl;
  return 0;
}

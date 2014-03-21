#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b) {
  string::reverse_iterator i= a.rbegin();
  string::reverse_iterator j=b.rbegin();
  string ret;
  int carry = 0;
  int tmp;
  while(i!=a.rend()||j!=b.rend()){
    if(i!=a.rend()&&j!=b.rend()){
      tmp = (*i-'0')+(*j-'0')+carry;
      i++;
      j++;
    }else if(i!=a.rend()){
      tmp = (*i-'0')+carry; 
      i++;
    }else{
      tmp = (*j-'0')+carry;
      j++;
    }
    if(tmp>1){
      carry = 1;
      tmp %=2;
    } else
      carry = 0;
    ret.insert(ret.begin(),tmp+'0');
  }
  if(carry){
    ret.insert(ret.begin(),'1');
  }
  return ret;
}
int main(){
  string a="11";
  string b="11";
  cout<<addBinary(a,b)<<endl;
  return 0;
}


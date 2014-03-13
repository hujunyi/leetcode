#include<iostream>
using namespace std;
int lengthOfLastWord(const char* s){
  int ret=0;
  while(*s){
    if(*s!=' '){
      ret++;
    }
    else
      ret=0;
    s++;
  }
  return ret;
}
int main(){
  const char s[] = "Hello World";
  cout<<lengthOfLastWord(s)<<endl;
  return 0;
}


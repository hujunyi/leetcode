#include<iostream>
#include<regex>
#include<cstring>
using namespace std;
bool isNumber(const char *s) {
  regex e ("\\s*[+-]?(\\d+\\.?|\\.\\d+)\\d*(e[+-]?\\d+)?\\s*");
  return regex_match(s,s+strlen(s)-1,e);
}
int main(){
  cout<<isNumber("1.2")<<endl;
}

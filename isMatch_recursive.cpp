#include<iostream>
using namespace std;
bool isMatch(const char *s, const char *p){
  if(*s=='\0'&&*p=='\0')
    return true;
  if(*s==*p||*p=='?')
    return isMatch(s+1,p+1);
  if(*p=='*'){
    int i=0;
    while(true){
      if(*(s+i)!='\0'){
        if(isMatch(s+i,p+1))
         return true; 
        else
          i++;
      }else
        return isMatch(s+i,p+1);
    }
  }
  return false;
}
int main(){
  char s[] = "aab";
  char p[] = "c*a*b";
  cout<<isMatch(s,p)<<endl;
  return 0;
}
  

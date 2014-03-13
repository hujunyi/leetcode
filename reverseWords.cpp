#include<iostream>
#include<string>
#include<stack>
using namespace std;
void reverseWords(string &s) {
  stack<string> St;
  string tmp;
  tmp.clear();
  for(string::iterator i=s.begin();i!=s.end();i++){
    if(*i!=' '){
      tmp.push_back(*i);
    }else if(!tmp.empty()){
      St.push(tmp);
      tmp.clear();
    }
  }
  if(!tmp.empty()){
    St.push(tmp);
    tmp.clear();
  }
  s.clear();
  while(!St.empty()){
    tmp = St.top();
    if(s.empty()){
      s.insert(s.size(),tmp);
    }else{
      s.insert(s.size()," ");
      s.insert(s.size(),tmp);
    }
    St.pop();
  }

}
int main(){
  string s = "the sky is blue";
  reverseWords(s);
  cout<<s<<endl;
  return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string multiplye(string num1, string num2){
  int carry = 0;
  string ret;
  char tmp;
  vector<string> mediators;
  for(string::reverse_iterator i=num1.rbegin();i!=num1.rend();i++){
    int multiplier1 = *i - '0';
    string mediator;
    for(int k=0;k<i-num1.rbegin();k++){
      mediator.push_back('0');
    }
    for(string::reverse_iterator j=num2.rbegin();j!=num2.rend();j++){
      int multiplier2 = *j - '0'; 
      int product = multiplier1*multiplier2;
      tmp = (product+carry)%10+'0';
      mediator.insert(mediator.begin(),tmp);
      carry = (product+carry)/10;
    }
    if(carry>0){
      tmp = carry + '0'; 
      mediator.insert(mediator.begin(),tmp);
    }
    mediators.push_back(mediator);
    carry =0;
  }
  carry = 0;
  tmp = '0';
  bool a= false;
  while(true){
    int sum=0;
    if(mediators.size()>0){
      for(vector<string>::iterator i=mediators.begin();i!=mediators.end();i++){
          int addend =(*i).back()-'0';
          sum +=addend;
          (*i).pop_back();
          if((*i).size()==0){
            mediators.erase(i);
            i--;
          }
      }
      
      tmp = (sum+carry)%10+'0';
      ret.insert(ret.begin(),tmp);
      carry = (sum+carry)/10;
    } 
    else{
      if(carry>0){
        tmp = carry+'0';
        ret.insert(ret.begin(),tmp);
      }
      break;
    }
  }
  return ret;          
}
int main(){
  string a = "120";
  string b = "456";
  cout<<multiplye(a,b)<<endl;
  return 0;
}
  
  

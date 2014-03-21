#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double a=10.0;
  double b = sqrt(a);
  double c;
  
  cout<<modf(b,&c)<<endl;
  return 0;
}

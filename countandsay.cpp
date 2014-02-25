#include<iostream>
#include<string>
using namespace std;
string next_sequence(string s){
	int pre=s[0];
	int count=1;
	string ret;
	if(s.size()==0)
		return ret;
	if(s.size()==1){
	 ret.push_back('0'+1);	
	 ret.push_back(s[0]);
	 return ret;
	}
	for(int i=1;i<s.size();i++){
		if(pre == s[i])
			count++;
		else{
			char c = '0'+count;
			char num = pre; 
			ret.push_back(c);
			ret.push_back(num);
			count=1;
			pre = s[i];
		}
		pre = s[i];
	}
	char c = '0'+count;
	char num = s.back();
	ret.push_back(c);
	ret.push_back(num);
	return ret;
}
int main(){
	string c;
	cin>>c;
	cout<<next_sequence(c)<<endl;
	return 0;
}

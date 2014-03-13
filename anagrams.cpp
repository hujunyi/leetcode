#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<string> anagrams(vector<string> &strs) {
  map<string,int> anagrams;
  vector<string> ret;
  for(vector<string>::iterator i=strs.begin();i!=strs.end();i++){
    string tmp = *i;
    sort(tmp.begin(),tmp.end());
    map<string,int>::iterator f = anagrams.find(tmp);
    if(f!=anagrams.end()){
      ret.push_back(*i);
      if(f->second!=-1){
        ret.push_back(strs[f->second]);
        f->second=-1;
      }
    }
    else{
      anagrams.insert(pair<string,int>(tmp,i-strs.begin()));
    }
  }
  return ret;
}
int main(){
  vector<string> strs;
  strs.push_back("tea");
  strs.push_back("and");
  strs.push_back("ate");
  strs.push_back("eat");
  strs.push_back("den");
  vector<string> ret = anagrams(strs);
  for(int i=0;i<ret.size();i++){
    cout<<ret[i]<<endl;
  }
  return 0;
}

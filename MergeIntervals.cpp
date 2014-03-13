#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
bool less_than(Interval a,Interval b){
  return a.start<b.start;
}
bool canMerge(Interval a,Interval b){
  if(a.end<b.start||a.start>b.end)
    return false;
  else
    return true;
}
vector<Interval> merge(vector<Interval> &intervals) {
  vector<Interval> ret;
  sort(intervals.begin(),intervals.end(),less_than);
  vector<Interval>::iterator i=intervals.begin();
  while(i!=intervals.end()){
    if(i+1!=intervals.end()&&canMerge(*i,*(i+1))){
      (i+1)->start = min(i->start,(i+1)->start);
      (i+1)->end = max(i->end,(i+1)->end);
    }else{
      ret.push_back(*i);
    }
    i++;
  }
  return ret;
}

  
int main(){
  Interval a(1,4);
  Interval b(4,5);
  Interval c(8,10);
  Interval d(15,18);
  vector<Interval> intervals;
  //intervals.push_back(d);
  intervals.push_back(a);
  intervals.push_back(b);
  //intervals.push_back(c);
  vector<Interval> ret = merge(intervals);
  sort(intervals.begin(),intervals.end(),less_than);
  for(int i=0;i<ret.size();i++){
    cout<<ret[i].start<<" "<<ret[i].end<<endl;
  }
  return 0;
}


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
bool canMerge(Interval a,Interval b){
  if(a.end<b.start||b.end<a.start)
    return false;
  else
    return true;
}
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
  int start = newInterval.start;
  int end = newInterval.end;
  vector<Interval>::iterator i = intervals.begin();
  vector<Interval> ret;
  bool flag = false;
  while(i!=intervals.end()){
    if(i->start>newInterval.start){
      flag = true;
      intervals.insert(i,newInterval);
      break;
    }else
      i++;
  }
  
  if(!flag) intervals.insert(intervals.end(),newInterval);
  i=intervals.begin();
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
  Interval a(1,2);
  Interval b(3,5);
  Interval c(6,7);
  Interval d(8,10);
  Interval e(12,16);
  vector<Interval> intervals;
  intervals.push_back(a);
  intervals.push_back(b);
  intervals.push_back(c);
  intervals.push_back(d);
  intervals.push_back(e);
  Interval f(4,9);
  //    intervals.push_back(b);
  //
  vector<Interval> ret = insert(intervals,f);
  for(int i=0;i<ret.size();i++){
    cout<<ret[i].start<<" "<<ret[i].end<<endl;
  }
  return 0;
}


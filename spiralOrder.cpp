#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int> > &matrix) {
  vector<int> ret;
  if(matrix.size()==0)
    return ret;
  //up row
  for(vector<int>::iterator i=matrix[0].begin();i!=matrix[0].end();i++){
    ret.push_back(*i);
  }
  matrix.erase(matrix.begin());
  
  
  //right col
  for(vector<vector<int> >::iterator i=matrix.begin();i!=matrix.end();i++){
    ret.push_back((*i).back());
    (*i).pop_back();
  }
  vector<vector<int> >::iterator clear=matrix.begin();
  while(clear!=matrix.end()){
    if((*clear).size()==0)
      matrix.erase(clear);
    else
      clear++;
  }
  
  //down row
  if(matrix.size()!=0){
    vector<int> down = matrix.back();
    while(down.size()!=0){
      ret.push_back(down.back());
      down.pop_back();
    }
    matrix.pop_back();
  }
  //left col
  for(vector<vector<int> >::reverse_iterator i=matrix.rbegin();i!=matrix.rend();i++){
    ret.push_back((*i).front());
    (*i).erase((*i).begin());
  }
  clear=matrix.begin();
  while(clear!=matrix.end()){
    if((*clear).size()==0)
      matrix.erase(clear);
    else
      clear++;
  }
  if(matrix.size()==0){
    return ret;
  }
  else{
    vector<int> subret = spiralOrder(matrix);
    ret.insert(ret.end(),subret.begin(),subret.end());
    return ret;
  }  
}
int main(){
  vector<vector<int> > matrix;
  int A[] = {1,2,3,4};
  int B[] = {5,6,7,8};
  int C[] = {9,10,11,12};
  int D[] = {13,14,15,16};
  vector<int> Aa(A,A+sizeof(A)/sizeof(int));
  vector<int> Bb(B,B+sizeof(B)/sizeof(int));
  vector<int> Cc(C,C+sizeof(C)/sizeof(int));
  vector<int> Dd(D,D+sizeof(D)/sizeof(int));
  matrix.push_back(Aa);
  matrix.push_back(Bb);
  matrix.push_back(Cc);
  matrix.push_back(Dd);
  vector<int> ret = spiralOrder(matrix);
  for(int i=0;i<ret.size();i++){
    cout<<ret[i]<<" ";
  }
  cout<<endl;
  return 0;
}

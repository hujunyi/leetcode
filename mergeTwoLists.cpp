#include<iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if(l1==NULL) return l2;
  if(l2==NULL) return l1;
  ListNode *head = (l1->val>=l2->val)? l2:l1;
  ListNode *current = head;
  ListNode *index1 = (l1->val>=l2->val)? l1:l2;
  ListNode *index2 = current->next;
  while(index1!=NULL|| index2!=NULL){
    if(index1!=NULL && index2!=NULL){
      if(index1->val>=index2->val){
        current->next = index2;
        index2=index2->next;
      } else {
        current->next=index1;
        index1=index1->next;
      }
      current=current->next;
      continue;
    } else if(index1==NULL){
      current->next=index2;
      break;
    }else {
      current->next=index1;
      break;
    }
  }
  return head;
}
int main(){
  ListNode *l1=new ListNode(2);
  ListNode *l2 = new ListNode(1);
  ListNode *result = mergeTwoLists(l1,l2);
  while(result!=NULL){
    cout<<result->val<<" ";
    result=result->next;
  }
  cout<<endl;
  return 0;
}



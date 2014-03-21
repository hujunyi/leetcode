//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.
#include<iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *rotateRight(ListNode *head, int k) {
  ListNode *end = head;
  int length=0;
  while(end->next!=NULL){
    end=end->next;
    length++;
  }
  length++;
  k =k%length;
  if(k==0)
    return head;
  ListNode *start=head;
  ListNode *newEnd=head;
  for(int i=0;i<length-k-1;i++){
    newEnd=newEnd->next;
  }
  head = newEnd->next;
  newEnd->next=NULL;
  end->next=start;
  return head;
}
void showList(ListNode *head){
  ListNode *tmp=head;
  while(tmp!=NULL){
    cout<<tmp->val<<" ";
    tmp=tmp->next;
  }
  cout<<endl;
}
int main(){
  ListNode *head = new ListNode(1);
  ListNode *tmp = head;
  for(int i=2;i<=5;i++){
    tmp->next=new ListNode(i);
    tmp=tmp->next;
  }
  showList(head);
  tmp = rotateRight(head,19);
  showList(tmp);
  return 0;
}
    
  
  

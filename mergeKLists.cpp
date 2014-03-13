#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct ListNode 
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeKLists(vector<ListNode *> &lists) {
  // IMPORTANT: Please reset any member data you declared, as
  // the same Solution instance will be reused for each test case.
  vector<ListNode *>::iterator it = lists.begin();
  while(it!=lists.end())
  {
    if(*it==NULL)
      lists.erase(it);
    else
      it++;

  }
  if(lists.empty())
  {
    return NULL;
  }
  ListNode *ret=NULL;
  ListNode *index = NULL;
  vector<ListNode *>::iterator selected;
  int minval;
  while(lists.size()!=0)
  {

    for(vector<ListNode *>::iterator i=lists.begin();i!=lists.end();i++)
    {
      minval = (*i)->val;
      selected = i;
      break;
    }
    for(vector<ListNode *>::iterator i=lists.begin();i!=lists.end();)
    {
      if(((*i)->val)<minval)
      {

        minval = (*i)->val;
        selected = i;
      }
      i++;	
    }
    ListNode* removed = *selected;
    (*selected) = (*selected)->next;
    if((*selected)==NULL)
    {
      lists.erase(selected);
    }
    delete removed;
    if(ret==NULL)
    {

      ret = new ListNode(minval);
      index = ret;
    }
    else
    {
      index->next = new ListNode(minval);
      index = index->next;
    }
  }
  return ret;    
}
int main()
{
  ListNode* a = new ListNode(4);
  a->next = new ListNode(7);
  (a->next)->next = new ListNode(10);
  ListNode* b =new ListNode(2);
  b->next = new ListNode(5);
  (b->next)->next = new ListNode(6);
  ListNode* d = NULL;
  vector<ListNode *> lists;
  lists.push_back(a);
  lists.push_back(b);
  ListNode* c = mergeKLists(lists);
  while(c!=NULL)
  {
    cout<<c->val<<endl;
    c=c->next;
  }
  return 0;
}

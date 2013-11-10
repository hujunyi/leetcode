#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class comp {
 public:
    bool operator() (const ListNode* l, const ListNode* r) const {
        return (l->val > r->val);
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) {
	vector<ListNode *>::iterator it = lists.begin();
	while(it!=lists.end())
	{
		if(*it==NULL)
			lists.erase(it);
		else
			it++;
	}
	if(lists.empty())
		return NULL;
	make_heap(lists.begin(),lists.end(),comp());

	ListNode *head = NULL;
	ListNode *cur = NULL;
	while(!lists.empty())
	{
		pop_heap(lists.begin(),lists.end(),comp());
		int last = lists.size()-1;
		if(head==NULL)
		{
			head = new ListNode(lists[last]->val);
			cur = head;
		}
		else
		{
			cur->next = new ListNode(lists[last]->val);
			cur=cur->next;
		}
		lists[last] = lists[last]->next;

		if(lists[last]==NULL)
		{
			lists.pop_back();
		}
		else
		{
			push_heap(lists.begin(),lists.end(),comp());
		}
	}
	return head;
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
	

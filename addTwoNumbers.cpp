#include<string>
#include<memory>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode* head;
	ListNode* index1 = l1;
	ListNode* index2 = l2;
	ListNode* result = new ListNode(0);
	head = result;
	bool carry = false;
	while(true)
	{
		if(index1!=NULL)
		{
			result->val += index1->val;
			index1 = index1->next;
			
		}
		if(index2!=NULL)
		{
			result->val += index2->val;
			index2 = index2->next;
		}
		if(carry)
		{
			result->val=result->val+1;
		}
		
		if(result->val>=10)
		{
			carry = true;
			result->val = result->val%10;
		}
		else
		{
			carry = false;
		}
		if(index1!=NULL||index2!=NULL||carry)
		{

			result->next = new ListNode(0);
			result = result->next;
		}
		else
		{
			break;
		}
		
		
	}

	return head;
}
int main()
{
	ListNode* l1=new ListNode(7);
	l1->next = new ListNode(9);
	ListNode* l2=new ListNode(8);
	ListNode* head = addTwoNumbers(l1,l2);
	cout<<head->next->next->val<<endl;
}
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
	ListNode* result = NULL;
	int val;
	bool carry = false;
	while(index1!=NULL&&index2!=NULL)
	{
		val = index1->val+index2->val;
		if(carry)
			val++;
		carry = false;
		if(val>=10)
		{
			carry = true;
			val = val%10;
		}
		ListNode temp(val);
		if(result==NULL)
		{
			result = &temp;
			head = result;
		}
		else
		{
			result->next = &temp;
		}
		index1 = index1->next;
		index2 = index2->next;
		if(index1==NULL)
		{
			index1=index2;
		}
	}
	while(index1!=NULL)
	{
		if(carry)
			val = index1->val+1;
		carry =false;
		if(val>=10)
		{
			val = val%10;
			carry = true;
		}
		ListNode temp(val);
		if(result==NULL)
		{
			result = &temp;
			head = result;
			result = result->next;
		}
		else
		{
			result->next = &temp;
			result= result->next;
		}
		index1 = index1->next;	
	}
	if(carry)
	{
		ListNode temp(1);
		if(result==NULL)
		{
			result = &temp;
			head = result;
		}
		else
		{
			result->next = &temp;
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
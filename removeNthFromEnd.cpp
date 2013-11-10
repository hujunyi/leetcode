#include<iostream>
using namespace std;
struct ListNode {
		int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	int length = 0;
	ListNode *tmp = head;
	while(tmp!=NULL)
	{
		length++;
		tmp = tmp->next;
	}
	int target = length - n;
	tmp = head;
	if(target == 0)
	{
		 tmp=tmp->next;
		 delete head;
		 head = NULL;
		 return tmp;
	} 
	else
	{
		for(int i =0;i<target-1;i++)
		{
			tmp = tmp->next;
		}
		ListNode *remove = tmp->next;
		tmp->next = remove->next;
		delete remove;
		remove = NULL;
		tmp = NULL;
		return head;
	}
}
int main()
{
	ListNode *head = new ListNode(1);
	removeNthFromEnd(head,1);
	return 0;
}
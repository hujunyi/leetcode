#include<string>
#include<iostream>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int main()
{
	ListNode* a;
	ListNode* b;
	a = b;
	a=new ListNode();
	cout<<a->val;
	return 0;
}
#include"stdafx.h"
#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	int count = 0;
	ListNode* cur = head, *pre = head;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	int reserve_n = count + 1 - n;


	if (reserve_n == 0 || head == NULL)
	{
		return head;
	}

	cur = head->next;
	if (reserve_n == 1)
	{
		return cur;
	}

	int idx = 0;
	while (cur)
	{
		if (idx == reserve_n - 2)
		{
			pre->next = cur->next;
			break;
		}

		pre = cur;
		cur = cur->next;
		idx += 1;
	}

	return head;
}

int main()
{
	ListNode* lst_vec = new ListNode(1);
	removeNthFromEnd(lst_vec, 1);
	return 0;
}
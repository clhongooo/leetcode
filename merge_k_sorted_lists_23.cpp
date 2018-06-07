#include"stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	vector<ListNode*> nodes_vec;
	ListNode *result_list = NULL, *result_head = NULL;
	for (int i = 0; i < lists.size(); i++)
	{
		nodes_vec.push_back(lists[i]);
	}
	while (true)
	{
		bool is_finish = true;
		for (int i = 0; i < nodes_vec.size(); i++)
		{
			if (nodes_vec[i] != NULL)
			{
				is_finish = false;
				break;
			}
		}
		if (is_finish)
		{
			break;
		}

		int min_val = INT_MAX;
		int min_idx = -1;
		for (int i = 0; i < nodes_vec.size(); i++)
		{
			if (nodes_vec[i] && nodes_vec[i]->val < min_val)
			{
				min_val = nodes_vec[i]->val;
				min_idx = i;
			}
		}

		if (result_head == NULL)
		{
			result_head = nodes_vec[min_idx];
			nodes_vec[min_idx] = nodes_vec[min_idx]->next;
			result_list = result_head;
		}
		else
		{
			result_list->next = nodes_vec[min_idx];
			result_list = result_list->next;
			nodes_vec[min_idx] = nodes_vec[min_idx]->next;
		}
	}
	return result_head;
}

int main()
{
	vector<ListNode*> lst_vec = { new ListNode(2) , new ListNode(1), new ListNode(2) };
	mergeKLists(lst_vec);
	return 0;
}
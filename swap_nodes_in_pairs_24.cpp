#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) 
{
    if(head == NULL)
    {
        return head;
    }
    ListNode *pre = head, *cur = head->next;
    while(cur)
    {
        if(cur)
        {
            int tmp_val = cur->val;
            cur->val = pre->val;
            pre->val = tmp_val;
        }
        else
        {
            break;
        }
        
        pre = cur->next;
        if(pre == NULL)
        {
            break;
        }
        cur = pre->next;
    }
    return head;
}

int main()
{
    return 0;
}
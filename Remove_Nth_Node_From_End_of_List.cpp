/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int size(ListNode *head)
    {
        int sz = 0;
        while (head != 0)
        {
            head = head->next;
            sz++;
        }
        return sz;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == 0)
            return head;
        int sz = size(head) - n;
        if (sz == 0)
        {
            ListNode *node = head;
            head = head->next;
            return head;
        }
        ListNode *temp = head;
        for (int i = 1; i < sz; i++)
        {
            temp = temp->next;
        }
        ListNode *node = temp->next;
        temp->next = temp->next->next;
        delete node;
        return head;
    }
};
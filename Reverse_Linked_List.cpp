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
    void reverse_singly_linkedList(ListNode *&head, ListNode *node)
    {
        if (node == 0)
            return;
        if (node->next == NULL)
        {
            head = node;
            return;
        }
        reverse_singly_linkedList(head, node->next);
        node->next->next = node;
        node->next = NULL;
    }
    ListNode *reverseList(ListNode *head)
    {
        reverse_singly_linkedList(head, head);
        return head;
    }
};
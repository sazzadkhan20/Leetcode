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
    void delete_head(ListNode *&head)
    {
        ListNode *node = head;
        head = head->next;
        delete node;
    }
    ListNode *removeElements(ListNode *head, int v)
    {
        if (head == 0)
            return head;
        ListNode *curr = head;
        ListNode *prev = head;
        while (curr != NULL)
        {
            if (curr->val == v && curr == prev)
            {
                delete_head(head);
                curr = head;
                prev = head;
                continue;
            }
            else if (curr->val == v)
            {
                ListNode *node = curr;
                prev->next = curr->next;
                delete node;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
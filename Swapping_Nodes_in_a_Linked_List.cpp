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
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == 0)
            return head;
        int sz = size(head) - k + 1;
        int count = 0;
        ListNode *temp = head;
        ListNode *prev = head;
        ListNode *curr = head;
        while (temp != NULL)
        {
            count++;
            if (k == count && sz == count)
            {
                return head;
            }
            else if (k == count)
            {
                curr = temp;
            }
            else if (sz == count)
            {
                prev = temp;
            }
            temp = temp->next;
        }
        swap(curr->val, prev->val);
        return head;
    }
};
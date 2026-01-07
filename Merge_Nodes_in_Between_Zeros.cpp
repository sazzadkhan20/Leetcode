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
    void insert_at_tail(ListNode *&head, ListNode *&tail, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == 0)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == 0)
            return head;
        ListNode *newHead = NULL;
        ListNode *newTail = NULL;
        ListNode *temp = head;
        int sumNode = 0;
        while (temp != NULL)
        {
            if (temp->val == 0 && sumNode != 0)
            {
                insert_at_tail(newHead, newTail, sumNode);
                sumNode = 0;
            }
            sumNode += temp->val;
            temp = temp->next;
        }
        return newHead;
    }
};
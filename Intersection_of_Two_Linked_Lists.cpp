/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int size(ListNode *head)
    {
        int sz = 0;
        while (head != NULL)
        {
            sz++;
            head = head->next;
        }
        return sz;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int size1 = size(headA);
        int size2 = size(headB);
        if (size1 > size2)
        {
            for (int i = 0; i < size1 - size2; i++)
                headA = headA->next;
        }
        else if (size2 > size1)
        {
            for (int i = 0; i < size2 - size1; i++)
                headB = headB->next;
        }
        while (headA != NULL || headB != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return 0;
    }
};
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carrySum = 0;
        int result;
        int sum;
        // int count = 0;
        ListNode *root = NULL;
        ListNode *tail = NULL;
        while (l1 && l2)
        {
            sum = l1->val + l2->val;
            result = sum % 10;
            result += carrySum;
            if (result >= 10)
            {
                carrySum = result / 10;
                result = result % 10;
            }
            else
                carrySum = sum / 10;
            ListNode *newNode = new ListNode(result);
            l1 = l1->next;
            l2 = l2->next;
            if (!root)
            {
                root = newNode;
                tail = newNode;
                continue;
            }
            tail->next = newNode;
            tail = tail->next;
        }
        if (l1)
        {
            while (l1)
            {
                sum = l1->val + carrySum;
                l1 = l1->next;
                result = sum % 10;
                carrySum = sum / 10;
                ListNode *newNode = new ListNode(result);
                tail->next = newNode;
                tail = tail->next;
            }
        }
        else if (l2)
        {
            while (l2)
            {
                sum = l2->val + carrySum;
                l2 = l2->next;
                result = sum % 10;
                carrySum = sum / 10;
                ListNode *newNode = new ListNode(result);
                tail->next = newNode;
                tail = tail->next;
            }
        }
        if (carrySum == 1)
        {
            ListNode *newNode = new ListNode(1);
            tail->next = newNode;
            tail = tail->next;
        }
        return root;
    }
};
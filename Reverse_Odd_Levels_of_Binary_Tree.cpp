/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void swapNode(TreeNode *p, TreeNode *q, int level)
    {
        if (!p || !q)
            return;
        if (level % 2 != 0)
            swap(p->val, q->val);
        swapNode(p->left, q->right, level + 1);
        swapNode(p->right, q->left, level + 1);
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        swapNode(root->left, root->right, 1);
        return root;
    }
};
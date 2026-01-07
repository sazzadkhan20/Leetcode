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
    int sum;
    int preOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = preOrder(root->left);
        int r = preOrder(root->right);
        sum += abs(l - r);
        return l + r + root->val;
    }

    int findTilt(TreeNode *root)
    {
        sum = 0;
        int val = preOrder(root);
        return sum;
    }
};
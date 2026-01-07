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
    bool preOrder(TreeNode *root, int v)
    {
        if (!root)
            return true;
        if (root->val != v)
            return false;
        bool l = preOrder(root->left, v);
        bool r = preOrder(root->right, v);
        if (l && r)
            return true;
        else
            return false;
    }
    bool isUnivalTree(TreeNode *root)
    {
        return preOrder(root, root->val);
    }
};
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
    int diameter;
    int getHeightOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = getHeightOfBinaryTree(root->left);
        int r = getHeightOfBinaryTree(root->right);
        int dm = l + r;
        diameter = max(diameter, dm);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        diameter = INT_MIN;
        int a = getHeightOfBinaryTree(root);
        return diameter;
    }
};
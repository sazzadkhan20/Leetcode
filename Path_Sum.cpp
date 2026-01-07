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
    bool pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right && targetSum - root->val == 0)
            return true;
        bool l = pathSum(root->left, targetSum - root->val);
        bool r = pathSum(root->right, targetSum - root->val);
        return l || r;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return pathSum(root, targetSum);
    }
};
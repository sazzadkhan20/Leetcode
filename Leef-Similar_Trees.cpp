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
    vector<int> v1;
    vector<int> v2;
    void firstLeafNode(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            v1.push_back(root->val);
            return;
        }
        firstLeafNode(root->left);
        firstLeafNode(root->right);
    }
    void SecondLeafNode(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            v2.push_back(root->val);
            return;
        }
        SecondLeafNode(root->left);
        SecondLeafNode(root->right);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        firstLeafNode(root1);
        SecondLeafNode(root2);
        return v1 == v2;
    }
};
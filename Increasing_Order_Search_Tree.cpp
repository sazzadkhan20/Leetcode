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
    vector<TreeNode *> node;
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        node.push_back(root);
        inOrder(root->right);
    }
    TreeNode *inOrder_node_create()
    {
        TreeNode *root = node[0];
        int n = node.size() - 1;
        for (int i = 0; i < n; i++)
        {
            node[i]->left = NULL;
            node[i]->right = node[i + 1];
        }
        node[n]->left = NULL;
        node[n]->right = NULL;
        return root;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        inOrder(root);
        return inOrder_node_create();
    }
};
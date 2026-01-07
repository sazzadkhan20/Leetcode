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
    TreeNode *convert_array_to_BST(vector<int> v, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        TreeNode *lf = convert_array_to_BST(v, l, mid - 1);
        TreeNode *rh = convert_array_to_BST(v, mid + 1, r);
        root->left = lf;
        root->right = rh;
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return convert_array_to_BST(nums, 0, nums.size() - 1);
    }
};
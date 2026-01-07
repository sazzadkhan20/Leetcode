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
#include <bits/stdc++.h>
class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> v;
        inOrder(root, v);
        // 2 3 4 5 6 7
        // 12
        int l = 0, r = v.size() - 1;
        while (l < r)
        {
            int sum = v[l] + v[r];
            if (sum == k)
                return true;
            if (sum > k)
                r--;
            if (sum < k)
                l++;
        }
        return false;
    }
};
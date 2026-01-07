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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<TreeNode *> temp;
            bool flag = true;
            while (!q.empty())
            {
                // Node out of Queue
                TreeNode *p = q.front();
                q.pop();

                // Operation
                if (flag)
                    v.push_back(p->val);
                flag = false;

                // Children Push in Vector
                if (p->right)
                    temp.push_back(p->right);
                if (p->left)
                    temp.push_back(p->left);
            }
            for (auto node : temp)
                q.push(node);
        }
        return v;
    }
};
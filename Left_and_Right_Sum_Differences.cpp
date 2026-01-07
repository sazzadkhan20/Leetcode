#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &v)
    {
        vector<int> v1;
        vector<int> v2;
        vector<int> ans;

        int sum = 0;
        for (int val : v)
        {
            v1.push_back(sum);
            sum = sum + val;
        }
        sum = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            v2.push_back(sum);
            sum = sum + v[i];
        }
        int i = 0;
        int j = v.size() - 1;
        while (i <= j)
        {
            swap(v2[i], v2[j]);
            i++;
            j--;
        }
        for (int i = 0; i < v1.size(); i++)
        {
            int num = abs(v1[i] - v2[i]);
            ans.push_back(num);
        }
        return ans;
    }
};
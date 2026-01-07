#include <bits/stdc++.h>
class IndexTrack
{
public:
    int val;
    int idx;
    IndexTrack(int val, int idx)
    {
        this->val = val;
        this->idx = idx;
    }
};

bool cmp(IndexTrack l, IndexTrack r)
{
    return l.val < r.val;
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &v, int target)
    {
        vector<int> index;
        vector<IndexTrack> track;
        for (int i = 0; i < v.size(); i++)
        {
            track.push_back(IndexTrack(v[i], i));
        }
        sort(track.begin(), track.end(), cmp);

        int l = 0, r = v.size() - 1;
        while (l != r)
        {
            // 2 3 4
            // 5
            int sum = track[l].val + track[r].val;
            if (sum == target)
            {
                index.push_back(track[l].idx);
                index.push_back(track[r].idx);
                break;
            }
            if (sum > target)
                r--;
            if (sum < target)
                l++;
        }
        return index;
    }
};
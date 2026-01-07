class cmp
{
public:
    bool operator()(pair<int, int> &l, pair<int, int> &r)
    {
        return l.second < r.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &v, int k)
    {
        map<int, int> mp;
        vector<int> v1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int val : v)
        {
            mp[val]++;
        }
        for (auto it : mp)
            pq.push(it);
        while (k--)
        {
            v1.push_back(pq.top().first);
            pq.pop();
        }
        return v1;
    }
};
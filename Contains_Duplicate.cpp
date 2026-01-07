class Solution
{
public:
    bool containsDuplicate(vector<int> &v)
    {
        set<int> s;
        for (int val : v)
            s.insert(val);
        return s.size() != v.size();
    }
};
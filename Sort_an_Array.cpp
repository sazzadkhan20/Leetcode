class Solution
{
public:
    vector<int> create_min_heap(vector<int> v)
    {
        vector<int> v1;
        for (int val : v)
        {
            v1.push_back(val);
            int cur = v1.size() - 1;
            while (cur > 0)
            {
                int parent = (cur - 1) / 2;
                if (v1[parent] > v1[cur])
                    swap(v1[parent], v1[cur]);
                else
                    break;
                cur = parent;
            }
        }
        return v1;
    }
    int delete_min_heap(vector<int> &v)
    {
        if (v.empty())
            return 0;
        int last_idx = v.size() - 1;
        int val = v[0];
        v[0] = v[last_idx];
        v.pop_back();
        int cur = 0;
        while (true)
        {
            int left = cur * 2 + 1;
            int right = cur * 2 + 2;
            if (left <= last_idx && right <= last_idx)
            {
                if (v[left] <= v[right] && v[left] < v[cur])
                {
                    swap(v[cur], v[left]);
                    cur = left;
                }
                else if (v[right] < v[left] && v[right] < v[cur])
                {
                    swap(v[cur], v[right]);
                    cur = right;
                }
                else
                {
                    break;
                }
            }
            else if (left <= last_idx)
            {
                if (v[left] < v[cur])
                {
                    swap(v[cur], v[left]);
                    cur = left;
                }
                else
                    break;
            }
            else if (right <= last_idx)
            {
                if (v[right] < v[cur])
                {
                    swap(v[cur], v[right]);
                    cur = right;
                }
                else
                    break;
            }
            else
            {
                break;
            }
        }
        return val;
    }
    vector<int> sortArray(vector<int> &v)
    {
        v = create_min_heap(v);
        int n = v.size();
        vector<int> v1;
        for (int i = 0; i < n; i++)
        {
            v1.push_back(delete_min_heap(v));
        }
        v = v1;
        v1.clear();
        return v;
    }
};
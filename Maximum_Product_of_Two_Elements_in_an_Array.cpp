class Solution
{
public:
    vector<int> create_max_heap(vector<int> v)
    {
        vector<int> v1;
        for (int val : v)
        {
            v1.push_back(val);
            int cur = v1.size() - 1;
            while (cur > 0)
            {
                int parent = (cur - 1) / 2;
                if (v1[parent] < v1[cur])
                    swap(v1[parent], v1[cur]);
                else
                    break;
                cur = parent;
            }
        }
        return v1;
    }
    int delete_max_heap(vector<int> &v)
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
                if (v[left] >= v[right] && v[left] > v[cur])
                {
                    swap(v[cur], v[left]);
                    cur = left;
                }
                else if (v[right] > v[left] && v[right] > v[cur])
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
                if (v[left] > v[cur])
                {
                    swap(v[cur], v[left]);
                    cur = left;
                }
                else
                    break;
            }
            else if (right <= last_idx)
            {
                if (v[right] > v[cur])
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
    int maxProduct(vector<int> &v)
    {
        v = create_max_heap(v);
        int val1 = delete_max_heap(v);
        int val2 = delete_max_heap(v);
        v.push_back(val1);
        v.push_back(val2);
        return (val1 - 1) * (val2 - 1);
    }
};
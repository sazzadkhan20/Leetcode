class Solution
{
public:
    int pivotIndex(vector<int> &v)
    {
        vector<int> leftSum;
        vector<int> rightSum;
        leftSum.push_back(0);
        rightSum.push_back(0);
        int sum = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            sum += v[i];
            leftSum.push_back(sum);
        }
        sum = 0;
        for (int i = v.size() - 1; i > 0; i--)
        {
            sum += v[i];
            rightSum.push_back(sum);
        }
        int l = 0;
        int r = rightSum.size() - 1;
        while (l <= r)
        {
            swap(rightSum[l], rightSum[r]);
            l++;
            r--;
        }
        for (int i = 0; i < rightSum.size(); i++)
        {
            if (leftSum[i] == rightSum[i])
                return i;
        }
        return -1;
    }
};
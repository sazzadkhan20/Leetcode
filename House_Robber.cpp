class Solution
{
public:
    vector<int> v;
    int dp[1000];
    int max_Value(int n)
    {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int op1 = v[n - 1] + max_Value(n - 2);
        int op2 = max_Value(n - 1);
        return dp[n] = max(op1, op2);
    }
    int rob(vector<int> &nums)
    {
        v = nums;
        memset(dp, -1, sizeof(dp));
        return max_Value(v.size());
    }
};
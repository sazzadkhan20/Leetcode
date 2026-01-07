class Solution
{
public:
    vector<int> Cost;
    int dp[10000];
    int min_Value(int n)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        if (n >= 2)
            return dp[n] = Cost[n - 1] + min(min_Value(n - 1), min_Value(n - 2));
        return dp[n] = Cost[n - 1] + min_Value(n - 1);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        Cost = cost;
        Cost.push_back(0);
        memset(dp, -1, sizeof(dp));
        return min_Value(Cost.size());
    }
};
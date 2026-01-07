class Solution
{
public:
    int dp[100];
    int steps(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = steps(n - 1) + steps(n - 2);
    }
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return steps(n);
    }
};
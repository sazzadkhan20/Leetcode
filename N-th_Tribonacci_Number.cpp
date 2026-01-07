class Solution
{
public:
    int dp[50];
    int tri(int n)
    {
        if (n < 2)
            return n;
        if (n < 3)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = tri(n - 1) + tri(n - 2) + tri(n - 3);
    }
    int tribonacci(int n)
    {
        memset(dp, -1, sizeof(dp));
        return tri(n);
    }
};
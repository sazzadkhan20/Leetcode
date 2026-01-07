class Solution
{
public:
    int dp[50];
    int fibonnacci(int n)
    {
        if (n < 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fibonnacci(n - 1) + fibonnacci(n - 2);
    }
    int fib(int n)
    {
        memset(dp, -1, sizeof(dp));
        return fibonnacci(n);
    }
};
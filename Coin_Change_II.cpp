class Solution
{
public:
    int dp[305][5005];
    int max_way(int n, vector<int> coins, int amount)
    {
        if (n == 0)
        {
            if (amount == 0)
                return 1;
            return 0;
        }
        if (dp[n][amount] != -1)
            return dp[n][amount];
        if (coins[n - 1] <= amount)
        {
            int op1 = max_way(n, coins, amount - coins[n - 1]);
            int op2 = max_way(n - 1, coins, amount);
            return dp[n][amount] = op1 + op2;
        }
        return dp[n][amount] = max_way(n - 1, coins, amount);
    }
    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof(dp));
        return max_way(coins.size(), coins, amount);
    }
};
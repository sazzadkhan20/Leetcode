const int N = 205;
const int S = 2e4 + 5;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int v : nums)
            sum += v;
        if (sum % 2 != 0)
            return false;
        bool dp[205][S];
        dp[0][0] = true;
        sum /= 2;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = false;
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[nums.size()][sum])
            return true;
        return false;
    }
};
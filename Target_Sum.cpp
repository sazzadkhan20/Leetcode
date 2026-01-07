const int N = 22;
const int S = 2e4 + 5;
class Solution
{
public:
    int dp[N][S];
    int countSubsetSum(vector<int> nums, int n, int sum)
    {
        if (n == 0)
        {
            if (sum == 0)
                return 1;
            return 0;
        }
        if (dp[n][sum] != -10000)
            return dp[n][sum];
        if (nums[n - 1] <= sum)
            return dp[n][sum] = countSubsetSum(nums, n - 1, sum - nums[n - 1]) + countSubsetSum(nums, n - 1, sum);
        return dp[n][sum] = countSubsetSum(nums, n - 1, sum);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = 0;
        for (int v : nums)
            totalSum += v;
        if ((target + totalSum) % 2 != 0 || (target + totalSum) < 0)
            return 0;
        int s1 = (target + totalSum) / 2;
        for (int i = 0; i <= nums.size(); i++)
        {
            for (int j = 0; j <= s1; j++)
                dp[i][j] = -10000;
        }
        return countSubsetSum(nums, nums.size(), s1);
    }
};
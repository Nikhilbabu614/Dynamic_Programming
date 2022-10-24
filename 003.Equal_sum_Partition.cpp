// Can subset be divided into equal paritions -- True / False
bool solve(vector<int> a, int sum)
{
    int n = a.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i : nums)
        sum += i;
    if (sum % 2)
        return false;
    return solve(nums, sum / 2);
}
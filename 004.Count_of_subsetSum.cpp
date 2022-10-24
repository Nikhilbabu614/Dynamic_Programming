// Count number of subsets with given sum

int perfectSum(int A[], int n, int sum)
{
    int M = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (A[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - A[i - 1]] + dp[i - 1][j]) % M;
            }
            else
                dp[i][j] = dp[i - 1][j] % M;
        }
    }
    return dp[n][sum] % M;
}
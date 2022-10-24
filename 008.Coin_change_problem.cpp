// count number of ways
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1, 0));
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}



// minimum number of total coins to given sum
int minCoins(int coins[], int M, int v)
{
    vector<vector<int>> dp(M + 1, vector<int>(v + 1, INT_MAX - 1));
    for (int i = 1; i <= M; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= v; j++)
        if (j % coins[0])
            dp[1][j] = INT_MAX - 1;
        else
            dp[1][j] = j / coins[0];

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[M][v] == INT_MAX - 1)
        return -1;
    return dp[M][v];
}
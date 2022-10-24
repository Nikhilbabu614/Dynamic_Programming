// Recursion
int recur(int w, int wt[], int val[], int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (wt[n - 1] <= w)
    {
        int v1 = val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1);
        int v2 = recur(w, wt, val, n - 1);
        return max(v1, v2);
    }
    else
        return recur(w, wt, val, n - 1);
}



// DP -  Memoization - bottom up
int recur(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (w == 0 || n == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        int v1 = val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1, dp);
        int v2 = recur(w, wt, val, n - 1, dp);
        return dp[n][w] = max(v1, v2);
    }
    else
        return dp[n][w] = recur(w, wt, val, n - 1, dp);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return recur(W, wt, val, n, dp);
}




// DP - Top_Down
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
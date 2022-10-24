// Recursion
int solve(int arr[], int n, int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, n, i, k) + solve(arr, n, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
        ans = min(ans, temp);
    }
    return ans;
}
int matrixMultiplication(int N, int arr[])
{
    return solve(arr, N, 1, N - 1);
}




// Recursion => bottom-up
int solve(int arr[], int n, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, n, i, k, dp) + solve(arr, n, k + 1, j, dp) 
            + arr[i - 1] * arr[j] * arr[k];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return solve(arr, N, 1, N - 1, dp);
}

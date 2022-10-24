// Does array contain a subset with given sum - True/False

bool solve(vector<int> &A, int sum) {
    int n = A.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(A[i-1]<=j){
                dp[i][j] = (dp[i-1][j-A[i-1]] || dp[i-1][j]);
            }else dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[n][sum];
}
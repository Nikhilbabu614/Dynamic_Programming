// partiton into subsets such that minimum difference
    int minimumDifference(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i : nums)sum+=i;
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum/2 + 1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else dp[i][j]=dp[i-1][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<sum/2+1;i++){
            if(dp[n-1][i])ans=min(ans,sum-2*i);
        }
        return ans;
    }
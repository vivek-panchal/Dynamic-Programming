// Recursive
int solve(vector<int>& nums, int k,int i){
         if(i == 0) {
            if(k == 0 && nums[i] == 0) return 2;
            if(k == 0 || nums[i] == k) return 1;
            return 0;
    }
        int notPick = solve(nums,k,i-1);
        int pick=0;
        if(nums[i]<=k)
            pick=solve(nums,k-nums[i],i-1);
        return pick+notPick;
    }
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    return solve(num,tar,n-1);
}

// memoization 
int solve(vector<int>& nums, int k,int i,vector<vector<int>> &dp){
        if(i == 0) {
            if(k == 0 && nums[i] == 0) return 2;
            if(k == 0 || nums[i] == k) return 1;
            return 0;
    }
        if(dp[i][k]!=-1)
            return dp[i][k];
        int notPick = solve(nums,k,i-1,dp);
        int pick=0;
        if(nums[i]<=k)
            pick=solve(nums,k-nums[i],i-1,dp);
        return dp[i][k]=pick+notPick;
    }
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return solve(num,tar,n-1,dp);
}

// Tabulation
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(num[0]<=tar)
        dp[0][num[0]]=1;
    for(int i=1;i<n;i++){
        for(int k=0;k<=tar;k++){
            int notPick = dp[i-1][k];
            int pick=0;
            if(num[i]<=k)
                pick=dp[i-1][k-num[i]];
            dp[i][k]=pick+notPick;
        }
    }
    return dp[n-1][tar];
}

// Space optemize
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    //vector<vector<int>> dp(n,vector<int>(tar+1,0));
    vector<int> prev(tar+1,0);
    vector<int> curr(tar+1,0);
    
    prev[0]=curr[0]=1;
    
    if(num[0]<=tar)
        prev[num[0]]=1;
    for(int i=1;i<n;i++){
        for(int k=0;k<=tar;k++){
            int notPick = prev[k];
            int pick=0;
            if(num[i]<=k)
                pick=prev[k-num[i]];
            curr[k]=pick+notPick;
        }
        prev=curr;
    }
    return prev[tar];
}

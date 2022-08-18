// Rexcursive
bool solve(int index,int k,vector<int> &arr){
    if(k==0)
        return true;
    if(index==0)
        return arr[0]==k;
    bool take =false;
    if(arr[index]<=k)
        take=solve(index-1,k-arr[index],arr);
    bool notTake=solve(index-1,k,arr);
    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1,k,arr);
}

// memoization
bool solve(int index,int k,vector<int> &arr,vector<vector<int>> &dp){
    if(k==0)
        return true;
    if(index==0)
        return arr[0]==k;
    if(dp[index][k]!=-1)
        return dp[index][k];
    bool take =false;
    if(arr[index]<=k)
        take=solve(index-1,k-arr[index],arr,dp);
    bool notTake=solve(index-1,k,arr,dp);
    return dp[index][k]=take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}

//Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool take =false;
            if(arr[index]<=target)
                take=dp[index-1][target-arr[index]];
            bool notTake=dp[index-1][target];
             dp[index][target]=take || notTake;
        }
    }
    return dp[n-1][k];
}

// space optimize
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0); 
    vector<bool> curr(k+1,0); 
    
    prev[0]=true;
    curr[0]=true;
    
    prev[arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool take =false;
            if(arr[index]<=target)
                take=prev[target-arr[index]];
            bool notTake=prev[target];
             curr[target]=take || notTake;
        }
        prev=curr;
    }
    return prev[k];
}

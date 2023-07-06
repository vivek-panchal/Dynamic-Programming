**//Recursive **

int solve(int index,vector<int> &nums){
    if(index==0)
        return nums[0];
    if(index<0)
        return 0;
    int pick=nums[index]+solve(index-2,nums);
    int dontPick=0+ solve(index-1,nums);
    return max(pick,dontPick);
}
int rob(vector<int> &nums){
    int n= nums.size();
    return solve(n-1,nums);
}
// memoization

int solve(int index,vector<int> &nums,vector<int>&dp){
    if(index==0)
        return nums[0];
    if(index<0)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int pick=nums[index]+solve(index-2,nums,dp);
    int dontPick=0+ solve(index-1,nums,dp);
    return dp[index]=max(pick,dontPick);
}
int rob(vector<int> &nums){
    int n= nums.size();
    vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}
// tabulation

int rob(vector<int> &nums){
    int n= nums.size();
    vector<int> dp(n,-1);
     dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)
            pick+=dp[i-2];
        int dontPick=0+dp[i-1];
        dp[i]=max(pick,dontPick);
    }
    return (dp[n-1]);
}
// space optemization

int rob(vector<int> &nums){
    int n= nums.size();
    
     int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)
            pick+=prev2;
        int dontPick=0+prev;
        int curr=max(pick,dontPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

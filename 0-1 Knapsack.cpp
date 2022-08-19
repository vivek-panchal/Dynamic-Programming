// recursion 
int solve(vector<int> &weight, vector<int>& value, int n, int maxWeight){
    if(n==0){
        if(weight[n]<=maxWeight)
            return value[n];
        else
            return 0;
    }
    int notTake=0+solve(weight,value,n-1,maxWeight);
    int take=-1e6;
    if(weight[n]<=maxWeight)
        take=value[n]+solve(weight,value,n-1,maxWeight-weight[n]);
    return max(notTake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight,value,n-1,maxWeight);
}

// Memoization 
int solve(vector<int> &weight, vector<int>& value, int n, int maxWeight,vector<vector<int>> &dp){
    if(n==0){
        if(weight[n]<=maxWeight)
            return value[n];
        else
            return 0;
    }
    if(dp[n][maxWeight]!=-1)
        return dp[n][maxWeight];
    int notTake=0+solve(weight,value,n-1,maxWeight,dp);
    int take=-1e6;
    if(weight[n]<=maxWeight)
        take=value[n]+solve(weight,value,n-1,maxWeight-weight[n],dp);
    return dp[n][maxWeight]=max(notTake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    return solve(weight,value,n-1,maxWeight,dp);
}
//memoization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;i++)
        dp[0][i]=value[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
            int notTake=0+dp[i-1][j];
            int take=-1e6;
            if(weight[i]<=j)
                take=value[i]+dp[i-1][j-weight[i]];
             dp[i][j]=max(notTake,take);
        }
    }
    return dp[n-1][maxWeight];
}

// space optemize
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,0));
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
    for(int i=weight[0];i<=maxWeight;i++)
        prev[i]=value[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
            int notTake=0+prev[j];
            int take=-1e6;
            if(weight[i]<=j)
                take=value[i]+prev[j-weight[i]];
             curr[j]=max(notTake,take);
        }
        prev=curr;
    }
    return prev[maxWeight];
}

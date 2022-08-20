// recursion
int solve(int n, int w, vector<int> &profit, vector<int> &weight){
    
    if(n==0){
        return ((int)(w/weight[n]))*profit[0];
    }
    
    int notTake=0+solve(n-1,w,profit,weight);
    int take=-1e6;
    if(weight[n]<=w)
        take=profit[n]+solve(n,w-weight[n],profit,weight);
    return max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solve(n-1,w,profit,weight);
}

//Memoization
int solve(int n, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    
    if(n==0){
        return ((int)(w/weight[n]))*profit[0];
    }
    if(dp[n][w]!=-1)
        return dp[n][w];
    int notTake=0+solve(n-1,w,profit,weight,dp);
    int take=-1e6;
    if(weight[n]<=w)
        take=profit[n]+solve(n,w-weight[n],profit,weight,dp);
    return dp[n][w]=max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}

//tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int weig=0;weig<=w;weig++){
        dp[0][weig]=((int)(weig/weight[0]))*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake=0+dp[i-1][j];
            int take=0;
            if(weight[i]<=j)
                take=profit[i]+dp[i][j-weight[i]];
             dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][w];
}

// Space Optimize

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0);
    vector<int> curr(w+1,0);
    for(int weig=0;weig<=w;weig++){
        prev[weig]=((int)(weig/weight[0]))*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake=0+prev[j];
            int take=0;
            if(weight[i]<=j)
                take=profit[i]+curr[j-weight[i]];
             curr[j]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[w];
}

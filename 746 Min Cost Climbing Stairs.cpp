// Recursive 
class Solution {
public:
    int solve(vector<int>& cost,int n){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        return min(solve(cost,n-1),solve(cost,n-2)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        return min(solve(cost,n-2),solve(cost,n-1));
    }
};

//memoization

class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>&dp){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,n-2,dp),solve(cost,n-1,dp));
    }
};

//Tabulization

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int oneStep=dp[i-1];
            int twoStep=dp[i-2];
            dp[i]=min(oneStep,twoStep)+cost[i];
        }
        return min(dp[n-1],dp[n-2]); 
    }
};

// Space Optemize
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int prev=cost[1];
        int prev2=cost[0];
        for(int i=2;i<n;i++){
           int curr=min(prev,prev2)+cost[i];
            prev2=prev;
            prev=curr;
        }
        return min(prev,prev2);
    }
};

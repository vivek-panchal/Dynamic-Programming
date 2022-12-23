// memorization
class Solution {
public:
    int solve(int n, vector<int> &dp){
        //base case
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(n-1,dp) + solve(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// Tabulation
class Solution {
public:
    int fib(int n) {
        int prev=1;
        int prev2=0;
        if(n==0)
            return 0;
            
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};

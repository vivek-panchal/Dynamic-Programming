//similar to buy & sell 2 , just small change we cant buy next day of selling there fore in buy call we change ind+2 and base case should be ind>=size
//Memoization
```
class Solution {
public:
    int profit =INT_MIN;
    int solve(int ind,bool buy,vector<int>& prices,vector<vector<int>> &dp){
        if(ind>=prices.size())
            return 0;
        if( dp[ind][buy]!=-1)
            return  dp[ind][buy];
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices,dp)),(solve(ind+1,0,prices,dp)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices,dp)),(solve(ind+2,1,prices,dp)+prices[ind]));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
```
//Tabulation
```
class Solution {
public:
    int profit =INT_MIN;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max((0+dp[ind+1][1]),(-prices[ind]+dp[ind+1][0]));
                }
                else{
                    profit=max((0+dp[ind+1][0]),(prices[ind]+dp[ind+2][1]));
                }
                 dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
```


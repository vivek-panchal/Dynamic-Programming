//Recurtion
```
class Solution {
public:
    int profit =INT_MIN;
    int solve(int ind,bool buy,vector<int>& prices){
        if(ind==prices.size())
            return false;
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices)),(solve(ind+1,0,prices)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices)),(solve(ind+1,1,prices)+prices[ind]));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(0,1,prices);
    }
};
```
// memeoization
```
class Solution {
public:
    int profit =INT_MIN;
    int solve(int ind,bool buy,vector<int>& prices,vector<vector<int>> &dp){
        if(ind==prices.size())
            return 0;
        if( dp[ind][buy]!=-1)
            return  dp[ind][buy];
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices,dp)),(solve(ind+1,0,prices,dp)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices,dp)),(solve(ind+1,1,prices,dp)+prices[ind]));
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
// Tabulation
```
class Solution {
public:
    int profit =INT_MIN;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max((0+dp[ind+1][1]),(-prices[ind]+dp[ind+1][0]));
                }
                else{
                    profit=max((0+dp[ind+1][0]),(prices[ind]+dp[ind+1][1]));
                }
                 dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
```
// space optemization
```
class Solution {
public:
    int profit =INT_MIN;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> next(2,0),curr(2,0);
        next[0]=next[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max((0+next[1]),(-prices[ind]+next[0]));
                }
                else{
                    profit=max((0+next[0]),(prices[ind]+next[1]));
                }
                 curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};
```
// Simple using fore loop
```
class Solution {
public:
    int profit =0;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i-1]<prices[i]){
                profit+= prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
```

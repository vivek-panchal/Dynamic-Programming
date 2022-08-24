Same as buy and sell stocks 2 , just substract fee everytime whyen you sell stocks 
// Memoization
```
class Solution {
public:
    int profit=0;
    int solve(int ind,bool buy,vector<int>& prices,vector<vector<int>> &dp,int fee){
        if(ind==prices.size())
            return 0;
        if( dp[ind][buy]!=-1)
            return  dp[ind][buy];
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices,dp,fee)),(solve(ind+1,0,prices,dp,fee)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices,dp,fee)),(solve(ind+1,1,prices,dp,fee)+prices[ind]-fee));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
    }
};
```
//Tabulation 
```
class Solution {
public:
    int profit=0;
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max((0+dp[ind+1][1]),(-prices[ind]+dp[ind+1][0]));
                }
                else{
                    profit=max((0+dp[ind+1][0]),(prices[ind]+dp[ind+1][1]-fee));
                }
                 dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
```
//space optemize
```
class Solution {
public:
    int profit=0;
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> next(2,0),curr(2,0);
        next[0]=next[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max((0+next[1]),(-prices[ind]+next[0]));
                }
                else{
                    profit=max((0+next[0]),(prices[ind]+next[1]-fee));
                }
                 curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};
```

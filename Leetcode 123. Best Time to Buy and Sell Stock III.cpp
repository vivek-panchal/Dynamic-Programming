//Recursion
```
class Solution {
public:
    int profit=INT_MIN;
    int solve(int ind,bool buy,vector<int>& prices,int cap){
        if(ind==prices.size() || cap==0)
            return 0;
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices,cap)),(solve(ind+1,0,prices,cap)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices,cap)),(solve(ind+1,1,prices,cap-1)+prices[ind]));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int cap=2;
        return solve(0,1,prices,cap);
    }
};

```
//  Memoization
```
class Solution {
public:
    int profit=0;
    int solve(int ind,bool buy,vector<int>& prices,int cap,vector<vector<vector<int>>> &dp){
        if( cap==0 || ind==prices.size())
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        if(buy==1){
            profit=max((0+solve(ind+1,1,prices,cap,dp)),(solve(ind+1,0,prices,cap,dp)-prices[ind]));
        }
        else{
            profit=max((0+solve(ind+1,0,prices,cap,dp)),(solve(ind+1,1,prices,cap-1,dp)+prices[ind]));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int cap=2;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,cap,dp);
    }
};
```
//Tabulation
```
class Solution {
public:
    int profit=0;
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //--***NO NEED OF BASE CASE bcs evrthing already assine by 0
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        profit=max((0+dp[ind+1][1][cap]),(dp[ind+1][0][cap]-prices[ind]));
                    }
                    else{
                        profit=max((0+dp[ind+1][0][cap]),(dp[ind+1][1][cap-1]+prices[ind]));
                    }
                     dp[ind][buy][cap]=profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};
```
//Space Optemization
```
class Solution {
public:
    int profit=0;
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        
        
        //--***NO NEED OF BASE CASE bcs evrthing already assine by 0
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        profit=max((0+after[1][cap]),(after[0][cap]-prices[ind]));
                    }
                    else{
                        profit=max((0+after[0][cap]),(after[1][cap-1]+prices[ind]));
                    }
                     curr[buy][cap]=profit;
                }
            }
            after=curr;
        }
        
        return after[1][2];
    }
};
```

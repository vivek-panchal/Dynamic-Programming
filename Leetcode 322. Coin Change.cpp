// Recurstion 
```
class Solution {
public:
    int solve(int ind,int k,vector<int>& coins){
        if(k==0 )
            return 0;
        if(ind==0){
            if(k%coins[ind]==0)
                return k/coins[ind];
            else return 1e9;
        }
        
        int notTake= 0+solve(ind-1,k,coins);
        int take=1e9;
        if(k>=coins[ind])
            take= 1+solve(ind,k-coins[ind],coins);
        return dp[ind][k]= min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        int ans= solve(n-1,amount,coins);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};

```

//Memoization
```
class Solution {
public:
    int solve(int ind,int k,vector<int>& coins,vector<vector<int>> &dp){
        if(k==0 )
            return 0;
        if(ind==0){
            if(k%coins[ind]==0)
                return k/coins[ind];
            else return 1e9;
        }
        if( dp[ind][k]!=-1)
            return  dp[ind][k];
        
        int notTake= 0+solve(ind-1,k,coins,dp);
        int take=1e9;
        if(k>=coins[ind])
            take= 1+solve(ind,k-coins[ind],coins,dp);
        return dp[ind][k]= min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};
```
//Tabulation
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                dp[0][t]= t/coins[0];
            else dp[0][t]= 1e9;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=1e9;
                int notTake= 0+dp[i-1][tar];
                if(tar>=coins[i])
                    take= 1+dp[i][tar-coins[i]];
                 dp[i][tar]= min(take,notTake);
            }
        }
       int ans=dp[n-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};
```
// Space optemize
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                prev[t]= t/coins[0];
            else prev[t]= 1e9;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=1e9;
                int notTake= 0+prev[tar];
                if(tar>=coins[i])
                    take= 1+curr[tar-coins[i]];
                 curr[tar]= min(take,notTake);
            }
            prev=curr;
        }
       int ans=prev[amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};
```

//Recursion 
```
class Solution {
public:
    int solve(int ind,int k,vector<int>& coins){
        if(k==0 )
            return 1;
        if(ind==0){
            if(k%coins[ind]==0)
                return 1;
            else return 0;
        }
        
        int notTake= solve(ind-1,k,coins);
        int take=0;
        if(k>=coins[ind])
            take= solve(ind,k-coins[ind],coins);
        return  (take + notTake);
        
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        return solve(n-1,amount,coins);
    }
};
```
//Memoization
```
class Solution {
public:
    int solve(int ind,int k,vector<int>& coins,vector<vector<int>> &dp){
        if(k==0 )
            return 1;
        if(ind==0){
            if(k%coins[ind]==0)
                return 1;
            else return 0;
        }
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int notTake= solve(ind-1,k,coins,dp);
        int take=0;
        if(k>=coins[ind])
            take= solve(ind,k-coins[ind],coins,dp);
        return dp[ind][k]= (take + notTake);
        
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};
```
//Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                dp[0][t]= 1;
            else dp[0][t]= 0;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=0;
                int notTake= dp[i-1][tar];
                if(tar>=coins[i])
                    take= dp[i][tar-coins[i]];
                 dp[i][tar]= (take+notTake);
            }
        }
       return dp[n-1][amount];
        
    }
};
```
// Space Optimize
```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<int> prev(amount+1,0);
        vector<int>curr(amount+1,0); 
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                prev[t]= 1;
            else prev[t]= 0;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=0;
                int notTake= prev[tar];
                if(tar>=coins[i])
                    take= curr[tar-coins[i]];
                 curr[tar]= (take+notTake);
            }
            prev=curr;
        }
       return prev[amount];
        
    }
};

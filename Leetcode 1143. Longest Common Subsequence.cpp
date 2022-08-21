*UPVOTE IF ITS HELPFULL*
// Recurstion 
```
class Solution {
public:
    int solve(int ind1,int ind2,string text1, string text2){
        if(ind1<0 || ind2<0)
            return 0;

        if(text1[ind1]==text2[ind2])
            return  1 + solve(ind1-1,ind2-1,text1,text2);
        return max(solve(ind1-1,ind2,text1,text2),solve(ind1,ind2-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m=text2.size();

        return solve(n-1,m-1,text1,text2);
    }
};
```
//Memoization
```
class Solution {
public:
    int solve(int ind1,int ind2,string &text1, string &text2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2]= 1 + solve(ind1-1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2]=max(solve(ind1-1,ind2,text1,text2,dp),solve(ind1,ind2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};
```
//Tabulation
```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                     dp[i][j]= 1 + dp[i-1][j-1];
                else
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
```
//Space Optemize
```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        
        for(int j=0;j<=m;j++)
            prev[j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                     curr[j]= 1 + prev[j-1];
                else
                     curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};
```

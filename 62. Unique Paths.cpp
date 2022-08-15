// Recursion
class Solution {
public:
    int solve(int m, int n){
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)
            return 0;

        int left= solve(m-1,n);
        int up= solve(m,n-1);
        return left+up;
}
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};

// memoization
class Solution {
public:
    int solve(int m, int n,vector<vector<int>>&dp){
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];

        int left= solve(m-1,n,dp);
        int up= solve(m,n-1,dp);
        return dp[m][n]=left+up;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};

// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 && i==0)
                    dp[0][0]=1;
                else{
                    int up=0;
                    int left=0;
                    if(j>0)
                        up=dp[i][j-1];
                    if(i>0)
                        left=dp[i-1][j];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optemization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(j==0 && i==0)
                    temp[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0)
                        up=dp[j];
                    if(j>0)
                        left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};

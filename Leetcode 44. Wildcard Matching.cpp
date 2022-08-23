//Recurtion
```
class Solution {
public:
    bool solve(int i,int j,string &s, string &p){
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0 ){
            if(p[j]=='*' && j==0)
                return true;
            for(int x=0;x<=j;x++){
                if(p[x]!='*')
                    return false;
            }
             return true;
        }
            
        if(j<0 && i>=0 )
            return false;
        if(s[i]==p[j] || p[j]=='?'){
            return solve(i-1,j-1,s,p);
        }
        if(p[j]=='*')
            return solve(i,j-1,s,p) ||solve(i-1,j,s,p);
        return false;
        
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        return solve(n-1,m-1,s,p);
    }
};
```
//Memoization
```
class Solution {
public:
    bool solve(int i,int j,string &s, string &p,vector<vector<int>> &dp){
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0 ){
            if(p[j]=='*' && j==0)
                return true;
            for(int x=0;x<=j;x++){
                if(p[x]!='*')
                    return false;
            }
             return true;
        }   
        if(j<0 && i>=0 )
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*')
            return dp[i][j]=solve(i,j-1,s,p,dp) ||solve(i-1,j,s,p,dp);
        return dp[i][j] =false;
        
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};
```

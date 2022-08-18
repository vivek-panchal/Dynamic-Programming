// Recursion
```
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& mat){
		if(j<0 || j>=mat.size()) 
            return 1e6;
		if(i==mat.size()-1) 
            return mat[i][j];
		int left = mat[i][j] + solve(i+1,j-1,mat); 
		int down = mat[i][j] + solve(i+1,j,mat);
		int right = mat[i][j] + solve(i+1,j+1,mat);
		return min(down,min(left,right)); 
	}

	int minFallingPathSum(vector<vector<int>>& mat) {
		int n=mat.size();
		int ans=INT_MAX;
		for(int j=0;j<n;j++)
            ans=min(ans,solve(0,j,mat));
		return ans;
    }
};
```

// memeoization
```
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
		if(j<0 || j>=mat.size()) 
            return 1e6;
		if(i==0) 
            return mat[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
		int left = mat[i][j] + solve(i-1,j-1,mat,dp); 
		int down = mat[i][j] + solve(i-1,j,mat,dp);
		int right = mat[i][j] + solve(i-1,j+1,mat,dp);
		return dp[i][j]=min(down,min(left,right)); 
	}

	int minFallingPathSum(vector<vector<int>>& mat) {
		int n=mat.size();
		int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
		for(int j=0;j<n;j++)
            ans=min(ans,solve(n-1,j,mat,dp));
		return ans;
    }
};
```

// Tabulation
```
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
		int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0));
		for(int j=0;j<n;j++)
            dp[0][j]=mat[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=mat[i][j]+dp[i-1][j];
                int left=INT_MAX,right=INT_MAX;
                if(j-1>=0)
                     left=mat[i][j]+dp[i-1][j-1];
                if(j+1<n)
                     right=mat[i][j]+dp[i-1][j+1];
                dp[i][j]= min(up,min(left,right));
            }
        }
        ans=ans = *min_element(dp[n-1].begin(), dp[n-1].end());
		return ans;
    }
};
```

// space optemization 
```
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
		int ans=INT_MAX;
        vector<int>prev(n,0);
        vector<int> curr(n,0);
		for(int j=0;j<n;j++)
            prev[j]=mat[0][j];
        for(int i=1;i<n;i++){
           
            for(int j=0;j<n;j++){
                int up=mat[i][j]+prev[j];
                int left=INT_MAX,right=INT_MAX;
                if(j>0)
                     left=mat[i][j]+prev[j-1];
                if(j+1<n)
                     right=mat[i][j]+prev[j+1];
                curr[j]= min(up,min(left,right));
            }
            prev=curr;
        }
        ans=ans = *min_element(prev.begin(), prev.end());
		return ans;
    }
};
```

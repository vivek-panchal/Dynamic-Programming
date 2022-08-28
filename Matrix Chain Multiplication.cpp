// Memoization 

int solve(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if (i==j)
        return 0;
    int mini =1e9;
    if(dp[i][j]!=-1)
        return dp[i][j];
    for(int k=i;k<j;k++){
        int step= arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp)+ solve(k+1,j,arr,dp);
        mini =min(mini,step);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return solve(1,N-1,arr,dp);
}

//Tabulation
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini =1e9;
            for(int k=i;k<j;k++){
            int step= arr[i-1]*arr[k]*arr[j] + dp[i][k]+ dp[k+1][j];
            
            mini =min(mini,step);
        }
         dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}

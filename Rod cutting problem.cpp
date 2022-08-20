//Recursion
int solve(vector<int> &price, int length,int index){
    if(index==0)
        return length*price[0];
    int notTake=0+ solve(price,length,index-1);
    int take=-1e9;
    int rodLen=index+1;
    if(rodLen<=length)
        take=price[index]+solve(price,length-rodLen,index);
    return max(take,notTake);
}
int cutRod(vector<int> &price, int length)
{
	int n= price.size();
    return solve(price , length, n-1);
}

//Memoization
int solve(vector<int> &price, int length,int index,vector<vector<int>> &dp){
    if(index==0)
        return length*price[0];
    if(dp[index][length] !=-1)
        return dp[index][length];
    int notTake=0+ solve(price,length,index-1,dp);
    int take=-1e9;
    int rodLen=index+1;
    if(rodLen<=length)
        take=price[index]+solve(price,length-rodLen,index,dp);
    return dp[index][length]=max(take,notTake);
}
int cutRod(vector<int> &price, int length)
{
	int n= price.size();
    vector<vector<int>> dp(n,vector<int>(length+1,-1));
    return solve(price , length, n-1,dp);
}
// tabulation 
int cutRod(vector<int> &price, int length)
{
	int n= price.size();
    vector<vector<int>> dp(n,vector<int>(length+1,0));
    for(int i=0;i<=length;i++)
        dp[0][i]=i*price[0];
    for(int index=1;index<n;index++){
        for(int l=0;l<=length;l++){
            int notTake=0+ dp[index-1][l];
            int take=-1e9;
            int rodLen=index+1;
            if(rodLen<=l)
                take=price[index]+dp[index][l-rodLen];
             dp[index][l]=max(take,notTake);
        }
    }
    return dp[n-1][length];
}

//Space Optemize
int cutRod(vector<int> &price, int length)
{
	int n= price.size();
    vector<int> prev(length+1,0);
    vector<int> curr(length+1,0);    
    for(int i=0;i<=length;i++)
        prev[i]=i*price[0];
    for(int index=1;index<n;index++){
        for(int l=0;l<=length;l++){
            int notTake=0+ prev[l];
            int take=-1e9;
            int rodLen=index+1;
            if(rodLen<=l)
                take=price[index]+curr[l-rodLen];
             curr[l]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[length];
}


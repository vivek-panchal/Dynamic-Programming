class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
            int n= arr.size();
            vector<int> dp(n,1),count(n,1);
            int maxi=1;
            for(int i=0;i<n;i++){
                for(int prev=0;prev<i;prev++){
                    if(arr[prev]<arr[i] && 1+ dp[prev]>dp[i]){
                        dp[i]=dp[prev]+1;
                        count[i]=count[prev];
                    }
                    else if(arr[prev]<arr[i] && 1+ dp[prev]==dp[i]){
                        count[i]+=count[prev];
                    }
                }
                maxi=max(maxi,dp[i]);
             }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
                ans+=count[i];
        }
        return ans;
    }
};

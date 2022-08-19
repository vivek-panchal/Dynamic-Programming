int mod=(int)(1e9+7);
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<int> prev(tar+1,0);
    vector<int> curr(tar+1,0);
    
    if(num[0]==0)
        prev[0]=2;
    else
        prev[0]=1;
    
    if(num[0]!=0 && num[0]<=tar)
        prev[num[0]]=1;
    for(int i=1;i<n;i++){
        for(int k=0;k<=tar;k++){
            int notPick = prev[k];
            int pick=0;
            if(num[i]<=k)
                pick=prev[k-num[i]];
            curr[k]=(pick+notPick)%mod;
        }
        prev=curr;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    // acc to question we need count of subarray which have total array sum - subarray sum equal d , 
    //subarray sum1 - subarray sum2=d;
    // sum1 = totalsum-sum2;
    // totalSum - Sum2-sum2=d;
    //totalSum -d =2*sum2;
    // sum2=(totalSum-d)/2
    // we need to find total number of sub arrays which have sum = (totalsum-d)/2
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum-d<0 || (sum-d)%2)
        return 0;
    return findWays(arr,(sum-d)/2);
}



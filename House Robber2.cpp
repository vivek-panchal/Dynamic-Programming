// same as maximum sum of non adjacent element

long long int solve(vector<int> &nums){
    long long int n= nums.size();
    vector<int> dp(n,-1);
     long long int prev=nums[0];
    long long int prev2=0;
    for(int i=1;i<n;i++){
        long long int pick=nums[i];
        if(i>1)
            pick+=prev2;
       long long int dontPick=0+prev;
       long long int curr=max(pick,dontPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1,temp2;
    long long int n=valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)
            temp1.push_back(valueInHouse[i]);
        if(i!=n-1)
            temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1),solve(temp2));
}

class Solution {
public:
    bool solve(int n, int k, vector<int> &arr) {
        vector<bool> prev(2*k+1,0); 
        vector<bool> curr(2*k+1,0); 

        prev[0]=true;
        curr[0]=true;

        prev[arr[0]]=true;
        for(int index=1;index<n;index++){
            for(int target=1;target<=k;target++){
                bool take =false;
                if(arr[index]<=target)
                    take=prev[target-arr[index]];
                bool notTake=prev[target];
                 curr[target]=take || notTake;
            }
            prev=curr;
        }
        return prev[k];
}
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int k=0;
        if(n<=1)
            return false;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)
            return false;
        int target=sum/2;
        return solve(n,target,arr);
    }
};

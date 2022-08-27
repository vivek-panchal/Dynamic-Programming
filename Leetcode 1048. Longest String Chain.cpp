// same as longest increasing subsequence

class Solution {
public:
    bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}

    bool static comp(string &s1 , string &s2){
        return s1.size()<s2.size();
}
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<int> next(n+1,0),curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int notTake=0+ next[prev+1];
                int take=0;
                if(prev==-1 || compare(nums[ind],nums[prev])){
                    take=1+next[ind+1];
                }
                 curr[prev+1]= max(take,notTake);
            }
            next=curr;
        }
        return next[0];
    }
};

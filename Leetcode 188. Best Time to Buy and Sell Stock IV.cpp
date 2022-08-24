// Same As Buy sell Stock 3 just small change here cap is equal to k
class Solution {
public:
    int profit=0;
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        
        
        //--***NO NEED OF BASE CASE bcs evrthing already assine by 0
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==1){
                        profit=max((0+after[1][cap]),(after[0][cap]-prices[ind]));
                    }
                    else{
                        profit=max((0+after[0][cap]),(after[1][cap-1]+prices[ind]));
                    }
                     curr[buy][cap]=profit;
                }
            }
            after=curr;
        }
        
        return after[1][k];
    }
}; 

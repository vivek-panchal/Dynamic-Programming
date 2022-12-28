// traverse given array from begin and one from end and find longest incresing subsequence and Than find maxi using given formula 
#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+ dp1[prev] > dp1[i])
                dp1[i]=1+dp1[prev];
        }
    }
    
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev]<arr[i] && 1+ dp2[prev] > dp2[i])
                dp2[i]=1+dp2[prev];
        }
    }
    
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
} 

class Solution {
public:

    int helper(vector<int>& arr, int k, int idx, int n, vector<int>&dp)
    {
        if(idx >= n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int maxVal = INT_MIN;
        int ans = 0;
        int maxLen = idx + k;
        for(int j = idx; j < min(n,maxLen); j++)
        {
            maxVal = max(maxVal,arr[j]);
            ans = max(ans, (maxVal * (j-idx+1)) + helper(arr,k,j+1,n,dp));
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helper(arr,k,0,arr.size(),dp);
    }
};
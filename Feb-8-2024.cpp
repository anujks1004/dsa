class Solution {
public:

    int helper(int n,vector<int>&dp)
    {
        if(n <= 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++)
            ans = min(ans,1+helper(n- (i*i),dp));
        
        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
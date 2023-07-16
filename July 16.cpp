class Solution {
public:

   int helper(vector<vector<int>>& events, int k,int idx, vector<vector<int>>&dp)
    {
        if(k == 0 or idx == events.size())
            return 0;
        
        if(dp[idx][k] != -1)
            return dp[idx][k];
        int notTake = helper(events,k,idx + 1,dp);
        int i;
        for(i = idx + 1; i < events.size(); i++)
            if(events[i][0] > events[idx][1])
                break;
        int take = events[idx][2] + helper(events,k - 1,i,dp);
        return dp[idx][k] = max(notTake,take);
    }


    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(events,k,0,dp);
        
    }
};
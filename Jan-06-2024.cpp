class Solution {
public:
    int getNext(vector<vector<int>>&jobs,int low,int currEnd)
    {
        int high = jobs.size()-1;
        int result = jobs.size() + 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(jobs[mid][0] >= currEnd)
            {
                result = mid;
                high = mid - 1;
            }    
            else
                low = mid + 1;
        }
        return result;
    }

    int helper(vector<vector<int>>&jobs,int curr,vector<int>&dp)
    {
        if(curr >= jobs.size())
            return 0;
        if(dp[curr] != -1)
            return dp[curr];
        int nextIdx = getNext(jobs,curr+1,jobs[curr][1]);
        int take = jobs[curr][2] + helper(jobs,nextIdx,dp);
        int skip = helper(jobs,curr+1,dp);
        return dp[curr] = max(skip,take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n,vector<int>(3,0));
        for(int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        vector<int>dp(n,-1);
        sort(jobs.begin(),jobs.end());
        return helper(jobs,0,dp);
    }
};
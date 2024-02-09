class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        vector<int>dp(nums.size(),1);
        int maxLen = 1;
        int index = 0;
        vector<int>prev(nums.size(),-1);
        for(int i = 0; i < nums.size(); i++)
            prev[i] = i;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < i; j++)
                if(!(nums[i] % nums[j]))
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                        if(maxLen < dp[i])
                        {
                            maxLen = max(maxLen, dp[i]);
                            index = i;
                        }
                    }
                }
        for(int j = maxLen; j > 0; j--)
        {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
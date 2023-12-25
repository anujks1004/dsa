class Solution {
public:

    int helper(int idx, string s,vector<int>&dp)
    {
        if(idx == s.length())
            return 1;
        int ans = 0;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i = idx; i < s.length(); i++)
        {
            if(i-idx+1 > 2)
                break;
            string temp = s.substr(idx,i-idx+1);
            if(temp[0] == '0')
                break;
            int curr = stoi(temp);
            if(curr <= 26)
                ans = ans + helper(i+1,s,dp);
        }
        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return helper(0,s,dp);
    }
};
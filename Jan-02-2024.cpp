class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        unordered_map<int,int>freq;
        int maxFreq = INT_MIN;
        for(auto num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq,freq[num]);
        }
        for(int i = 0; i < maxFreq; i++)
        {
            vector<int>row;
            for(auto &x : freq)
            {
                if(x.second > 0)
                {
                    row.push_back(x.first);
                    x.second--;
                }
            }
            ans.push_back(row);
        }

        return ans;    
    }
};
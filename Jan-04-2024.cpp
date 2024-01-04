class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &x : nums)
            freq[x]++;
        
        int ans = 0;
        for(auto &num : freq)
        {
            int currFreq = num.second;
            if(currFreq == 1)
                return -1;
            if(currFreq % 3 == 0)
                ans += (currFreq/3);
            else
                ans = ans + 1 + (currFreq/3);

        }

        return ans;
    }
};
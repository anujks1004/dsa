class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int max_freq = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]] > max_freq)
                max_freq = freq[nums[i]];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[nums[i]] == max_freq)
                count++;
        }

        return count;
    }
};
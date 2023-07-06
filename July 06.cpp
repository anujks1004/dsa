class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;
        while(right < nums.size())
        {
            sum += nums[right++];
            while(sum >= target)
            {
                window = min(window, right - left);
                sum -= nums[left++];
            }
        }
        
        return window == INT_MAX ? 0 : window;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int c = 0, res = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                c++;
            
            while (j < n && c > 1) {
                if (nums[j] == 0)
                    c--;
                j++;
            }
            
            res = max(res, i-j+1);
        }
        
        return res == INT_MIN ? 0 : res-1;
    }
};
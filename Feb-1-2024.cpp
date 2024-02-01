class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n == 0 or (n % 3))
            return ans;
        for(int i = 2; i < n;)
        {
            if(nums[i] - nums[i-2] <= k)
                ans.push_back({nums[i-2],nums[i-1],nums[i]});
            else
                return {};
            i += 3;
        }

        return ans;
    }
};
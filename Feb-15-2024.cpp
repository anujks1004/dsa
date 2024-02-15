class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = -1;
        long long prefix_sum = nums[1] + nums[0]; 
        for(int i = 2; i < nums.size(); i++)
        {
            if(prefix_sum > nums[i])
                if(ans < prefix_sum + nums[i])
                    ans = prefix_sum + nums[i];
            prefix_sum += nums[i];
        }

        return ans;
    }
};
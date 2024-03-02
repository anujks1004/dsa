class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        int k = j;
        while(i <= j)
        {
            int left = pow(nums[i],2);
            int right = pow(nums[j],2);
            if(left > right)
                ans[k--] = left, i++;
                
            else
                ans[k--] = right, j--;
        }

        return ans;
    }
};
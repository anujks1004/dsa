class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        int pos = 0;
        for(int i = 0;i < 32;i++)
        {
            int count = 0;
            for(int j = 0;j < n;j++)
            {
                count += (nums[j] & 1);
                nums[j] = nums[j] >> 1;
            }
            count %= 3;
            ans = ans + pow(2,pos)*count;
            pos++;
        }

        return ans;
    }
};
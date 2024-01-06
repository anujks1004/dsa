class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int idx=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(idx<lis.size())
                lis[idx]=nums[i];
            else
                lis.push_back(nums[i]);
        }
        return lis.size();
    }
};
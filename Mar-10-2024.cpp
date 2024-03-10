class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(auto x : nums1)
            m[x]++;
        for(int i = 0; i < nums2.size(); i++)
            if(m[nums2[i]])
            {
                ans.push_back(nums2[i]);
                m.erase(nums2[i]);
            }
                
            
        return ans;
    }
};
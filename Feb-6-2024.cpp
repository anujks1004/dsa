class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(auto x:strs)
        {
            string temp=x;
            sort(temp.begin(),temp.end());
            m[temp].push_back(x);
        }
        for(auto i:m)
            ans.push_back(i.second);
        
        return ans;
    }
};
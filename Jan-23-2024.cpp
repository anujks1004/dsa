class Solution {
public:

    unordered_map<string,int>m;

    bool hasDuplicate(string s1, string s2)
    {
        vector<int>freq(26,0);
        for(auto x : s1)
        {
            if(freq[x-'a'] > 0)
                return true;
            freq[x-'a']++;
        }
        for(auto x : s2)
            if(freq[x-'a'] > 0)
                return true;
        
        return false;
    }

    int helper(vector<string>& arr, string temp, int idx, int n)
    {
        if(idx >= n)
            return 0;
        int exclude = 0;
        int include = 0;
        if(m.find(temp) != m.end())
            return m[temp];
        exclude = helper(arr,temp,idx+1,n);
        if(!hasDuplicate(arr[idx],temp))
            include = arr[idx].length() + helper(arr,temp+arr[idx],idx+1,n);
        
        return m[temp] = max(include,exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        m.clear();
        int n = arr.size();
        return helper(arr,temp,0,n);
        
    }
};
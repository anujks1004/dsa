class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        int count = 1;
        vector<pair<int,char>>freq;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i-1])
            {
                count++;
                continue;
            }
            freq.push_back({count,s[i-1]});
            count = 1;
        }
        freq.push_back({count,s[s.length()-1]});
        sort(freq.begin(),freq.end(),greater<pair<int,char>>());
        string ans = "";
        for(auto x : freq)
        {
            int count = x.first;
            char curr = x.second;
            while(count--)
                ans.push_back(curr);
        }
        return ans;
    }
};
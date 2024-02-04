class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        unordered_map<char,int>window;
        for(auto x : t)
            window[x]++;
        int desired = window.size();
        unordered_map<char,int>curr;
        int low = 0, high = 0;
        int start_idx = -1;
        int len = INT_MAX;
        int count = 0;
        while(high < s.length())
        {
            while(count < desired and high < s.length())
            {
                curr[s[high]]++;
                if(curr[s[high]] == window[s[high]])
                    count++;
                high++;
            }
            while(count == desired and low < high)
            {
                int currLen = high - low;
                if(len > currLen)
                {
                    len = currLen;
                    start_idx = low;
                }
                curr[s[low]]--;
                if(curr[s[low]] < window[s[low]])
                    count--;
                low++;
            }
        }
        if(len != INT_MAX)
            return s.substr(start_idx,len);
        return "";  
    }
};
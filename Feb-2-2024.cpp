class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>res;
        int minLen = to_string(low).length();
        int maxLen = to_string(high).length();
        for(int len = minLen; len <= maxLen; len++)
        {
            for(int i = 0; i < 10 - len; i++)
            {
                int ans = stoi(s.substr(i,len));
                if(ans >= low and ans <= high)
                    res.push_back(ans);
            }
        }

        return res;

    }
};
class Solution {
public:
    string makeGood(string s) {
        if(s.length() == 0)
            return s;
        string result = "";
        int i = 0;
        while(i < s.length())
        {
            if(result.size() > 0 and (result.back() + 32 == s[i] or result.back() - s[i] == 32))
                 result.pop_back();
            
            else
                result.push_back(s[i]);
            
            i++;

        }
        
        return result;

    }
};
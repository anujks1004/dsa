class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x : words)
        {
            string curr = x;
            reverse(x.begin(),x.end());
            if(x == curr)
                return curr;
        }

        return "";
    }
};
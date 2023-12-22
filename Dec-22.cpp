class Solution {
public:
    int maxScore(string s) {
        int count0 = 0;
        int count1 = 0;
        int maxScore = INT_MIN;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == '1')
                count1++;
        
        if(count1 == 0 or count1 == s.length())
            return s.length() - 1;

        for(int i = 0; i < s.length() - 1; i++)
        {
            if(s[i] == '0')
                count0++;
            else
                count1--;
            maxScore = max(maxScore, count0 + count1);
        }

        return maxScore;
    }
};
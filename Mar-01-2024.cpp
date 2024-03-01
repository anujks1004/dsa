class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length() - 1;
        if(s[n] != '1')
        {
            for(int i = n; i >= 0; i--)
            {
                if(s[i] == '1')
                {
                    s[i] = '0';
                    break;
                }
            }
            s[n] = '1';
        }

        sort(s.begin(),s.begin() + n,greater<char>());

        return s;
    }
};
class Solution {
public:

    bool isVowel(char ch)
    {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
        return true;

        return false;
    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int ct = 0;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                if(i >= n/2)
                    ct--;
                else
                    ct++;
            }
        }

        return ct == 0;
    }
};
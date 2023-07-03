class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i = 0;
        if(s.length() != goal.length())
            return 0;

        int first = -1;
        int second = -1;
        if(s==goal)
        {
            set<char> S(s.begin(),s.end());
            if(s.size()!=S.size())
                return true;
            return false;
        }
        int diff = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                diff++;
                if(first == -1)
                    first = i;
                else if(second == -1)
                    second = i;
                else if(diff > 2)
                    return false;
            }
        }
        
        if(diff ==2 and s[first] == goal[second] and s[second] == goal[first])
            return true;

        return false;
    }
};
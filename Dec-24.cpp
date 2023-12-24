class Solution {
public:
    int minOperations(string s) {
        int operations = 0;
        int minValue = INT_MAX;
        //starting with 0
        for(int i = 0; i < s.length(); i++)
        {
            if((i % 2) == 0 and s[i] == '1')
                operations++;
            
            if((i % 2) == 1 and s[i] == '0')
                operations++;
        }
        minValue = min(minValue, operations);
        operations = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if((i % 2) == 0 and s[i] == '0')
                operations++;
            
            if((i % 2) == 1 and s[i] == '1')
                operations++;
        }

        minValue = min(minValue,operations);
        return minValue;
    }
};
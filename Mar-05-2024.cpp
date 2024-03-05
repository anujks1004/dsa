class Solution {
public:
    int minimumLength(string s) {
        int low = 0;
        int high = s.length()-1;
        while(low < high)
        {
            if(s[low] == s[high]){
                while(low + 1 < high and s[low] == s[low+1])
                    low++;
                while(low < high - 1 and s[high] == s[high-1])
                    high--;
                low++;
                high--;
            }
            
            else
                break;
        }
        return high-low+1;
    }
};
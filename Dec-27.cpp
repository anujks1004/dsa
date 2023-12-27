class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.length();
        if(n < 2)
            return cost;
        
        int left = 0;
        int right = 1;
        while(right < n)
        {
            if(colors[left] != colors[right])
            {
                left = right;
                right++;
            }
            else
            {
                if(neededTime[left] < neededTime[right])
                {
                    cost += neededTime[left];
                    left = right;
                    right++;
                }

                else
                {
                    cost += neededTime[right];
                    right++;
                }
            }
        }

        return cost;
        
    }
};
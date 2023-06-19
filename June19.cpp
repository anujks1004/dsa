class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int max_height = 0;
        for(int i = 0; i < gain.size(); i++)
        {
            sum += gain[i];
            max_height = max(max_height, sum);
        }
        return max_height;
    }
};
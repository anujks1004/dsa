class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxWidth = INT_MIN;
        for(int i = 1; i < points.size(); i++)
        {
            int currX = points[i][0];
            int prevX = points[i-1][0];
            maxWidth = max(maxWidth, currX - prevX);
        }

        return maxWidth;
    }
};
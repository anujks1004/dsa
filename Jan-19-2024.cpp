class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1)
            return *min_element(matrix[0].begin(),matrix[0].end());
        for(int row = n - 2; row >= 0; row--)
        {
            for(int col = 0; col < n; col++)
            {
                if(col == 0)
                    matrix[row][col] += min(matrix[row+1][col+1],matrix[row+1][col]);
                else if(col == n - 1)
                    matrix[row][col] += min(matrix[row+1][col-1],matrix[row+1][col]);
                else
                    matrix[row][col] += min(matrix[row+1][col+1],min(matrix[row+1][col-1],matrix[row+1][col]));
            }
        }
        int ans = INT_MAX;
        for(int col = 0; col < n; col++)
            ans = min(ans, matrix[0][col]);
        
        return ans;
    }
};
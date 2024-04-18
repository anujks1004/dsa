class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j])
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int new_x = i + dx[k];
                        int new_y = j + dy[k];
                        if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col and grid[new_x][new_y] == 1)
                            continue;
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        int dx[8] = {-1,1,0,0,-1,1,-1,1};
        int dy[8] = {0,0,-1,1,-1,1,1,-1};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = img[i][j];
                int ct = 1;
                for(int k = 0; k < 8; k++)
                {
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if(new_x >= 0 and new_y >= 0 and new_x < m and new_y < n)
                    {
                        ct++;
                        sum += img[new_x][new_y];
                    }
                }
                ans[i][j] = sum / ct;
            }
        }

        return ans;
    }
};
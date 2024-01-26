class Solution {
public:
    int dp[51][51][51];
    long long mod = 1e9 + 7;
    int helper(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if(startRow == m or startRow == -1 or startColumn == n or startColumn == -1)
        return 1;
        if(maxMove <= 0)
            return 0;
        if(dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove];
        int up = helper(m,n,maxMove-1,startRow-1,startColumn);
        int down = helper(m,n,maxMove-1,startRow+1,startColumn);
        int left = helper(m,n,maxMove-1,startRow,startColumn-1);
        int right = helper(m,n,maxMove-1,startRow,startColumn+1);
        int total = (up % mod + down % mod + left % mod + right % mod) % mod;
        dp[startRow][startColumn][maxMove] = total;
        return dp[startRow][startColumn][maxMove];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helper(m,n,maxMove,startRow,startColumn);

    }
};
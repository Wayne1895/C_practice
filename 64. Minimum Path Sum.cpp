class Solution {
public:
/*
    int dp(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo){
    
        if(i==0 && j==0) return grid[0][0];
        if (memo[i][j] != -1) return memo[i][j];

        int fromTop = (i > 0) ? dp(i - 1, j, grid, memo) : INT_MAX;
        int fromLeft = (j > 0) ? dp(i, j - 1, grid, memo) : INT_MAX;

        return memo[i][j] = min(fromTop, fromLeft) + grid[i][j];
       
       
    }
*/
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        /*
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return dp(m-1, n-1, grid, memo);
        */
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];

        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            dp[i][0]  = dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j])+grid[i][j];
            }
        }

        return dp[m-1][n-1];
       
    }
};
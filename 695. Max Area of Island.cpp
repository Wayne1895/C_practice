class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0 || visited[i][j] == 1) return 0;
        visited[i][j] = 1;
        int area = 1;
        
                
        area+=dfs(i-1, j, grid, visited);
        area+=dfs(i+1, j, grid, visited);
        area+=dfs(i, j-1, grid, visited);
        area+=dfs(i, j+1, grid, visited);
            
    
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    maxarea = max(maxarea, dfs(i, j, grid, visited));
                }
            }
        }
        return maxarea;

        
    }
};
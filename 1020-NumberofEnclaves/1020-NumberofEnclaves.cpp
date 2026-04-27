// Last updated: 4/27/2026, 6:44:44 PM
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r ,int c){
        int n = grid.size();
        int m = grid[0].size();
        
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] != 1) return;

        grid[r][c] = 2;

        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};

        for(int i = 0;i<4 ;i++){
            dfs(grid, r+row[i], c+col[i]);
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1) dfs(grid,i,0);
        }

        for(int i = 0; i<n; i++){
            if(grid[i][m-1] == 1) dfs(grid,i,m-1);
        }

        for(int i = 0; i<m; i++){
            if(grid[0][i] == 1) dfs(grid,0,i);
        }

        for(int i = 0; i<m; i++){
            if(grid[n-1][i] == 1) dfs(grid,n-1,i);
        }

        int cnt  = 0;

        for(int i =0;i<n;i++){
            for(int j= 0; j<m ;j++){
                if(grid[i][j] == 1) cnt++;
                else if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }
        return cnt;
    }
};
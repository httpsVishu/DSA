class Solution {
private:
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m){
        //mark node as vis
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r,c});
        while (!q.empty()){
            //access node
            int r = q.front().first;
            int c = q.front().second;
            //pop krdo
            q.pop();
            //traverse in neighbours
            //assuming all 8 dirextion, so r and c value comes from -1, 0, +1

            //for (int delrow = -1; delrow <= 1; delrow++){                    use it for 8 direction
                //for (int delcol = -1; delcol <= 1; delcol++){

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                //check validity + should be land in grid + no vis in vis
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' &&
                    !vis[nrow][ncol]){
                        //make vis and push in q
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //make vis matrix
        vector<vector<int>> vis(n, vector<int> (m,0));
        int cnt = 0;
        //traverse over matrix and do bfs whenever unvisited and when land
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return cnt;
    }
};


//grid is char based, so use '' wherever used
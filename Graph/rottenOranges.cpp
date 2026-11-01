class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        //need to find all rotten oranges taki use queue me push kar sake
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){ //means rotten
                    q.push({{i,j}, 0}); //at time t = 0
                    vis[i][j] = 2; //mark visited
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        //we got all rotten pushed in queue
        int tm = 0; //our min time
        int drow[] = {-1, 0, +1, 0};  //up right down left
        int dcol[] = {0, +1, 0, -1};
        while (!q.empty()){
            //access front node
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);   //in case koi node 2 pe ho, and koi 3 pe, to next ko 4 se continue krna
            //now pop
            q.pop();
            //go through neighbours
            for (int i = 0; i < 4; i++){
                //access neightbour
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                //check validity + tomato original me fresh ho + vis me marked na ho
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 &&
                    vis[nrow][ncol] != 2){
                        //means valid fresh, rot it
                        q.push({{nrow, ncol}, t+1});
                        vis[nrow][ncol] = 2;
                    }
            }
        }
        //need to check koi reh to ni gya
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (vis[i][j] != 2 && grid[i][j] == 1){ //grid me fresh ho and vis me rotten na ho
                    return -1;
                }
            }
        }
        
        return tm;
    }
};

//need to do bfs as we need minimum time, no need to go in a depth, go via breadth

// could have reduced last check by maintaining a counter
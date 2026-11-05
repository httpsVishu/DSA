class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //make vis and dist matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        //make a queue, need to store cooridnate and cost
        queue<pair<pair<int, int>, int>> q;
        //find all 1s, as they are our start nodes, push them in queue and make them vis
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    //push
                    q.push({{i,j}, 0});
                    //mark vis
                    vis[i][j] = 1;
                } else{
                    vis[i][j] = 0;
                }
            }
        }
        //ab in start node ke neighbours dekhte jao and push them in queue
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while (!q.empty()){
            //access front el
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            //pop
            q.pop();
            //mark the distance in dist matrix, steps is the distance 
            dist[row][col] = steps;
            //ab uske neighbours pe jao and unvisited ho to push
            for (int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                //check validity + visited na ho
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0){
                        //push
                        q.push({{nrow, ncol}, steps + 1});
                        //mark as vis
                        vis[nrow][ncol] = 1;
                    }
            }
        }
        return dist;
    }
};

//need to find distance from nearest 0, striver did from nearest 1
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]){
        //mark in vis
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        //check 4 neighbours
        for (int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            //check validity + vis me 0 ho + baord me O ho, dfs unhi pe krenge na jo abhi unvisited h
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                    //call dfs
                    dfs(nrow, ncol, vis, board, delrow, delcol);
                }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, +1, 0, -1};

        //need a vis matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //traverse first and last row
        for (int j = 0; j < m; j++){
            //first row, unvisited ho and O ho
            if (!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board, delrow, delcol);
            }
            //last row, unvisited ho and O ho
            if (!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, vis, board, delrow, delcol);
            }
        }
        //traverse first and last col
        for (int i = 0; i < n; i++){
            //first col, unvisited ho and O ho
            if (!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board, delrow, delcol);
            }
            //last col, unvisited ho and O ho
            if (!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board, delrow, delcol);
            }
        }
        //now go to entire board and see konse el visited me 1 ho gye and board me O, vo cant be changed to X
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};


//logic is sirf boundary wale element ko dekho, agar vo O h to kabhi bhi X nhi ban skte, unpe dfs lgana, unse connected jitne bhi O hoge, they too, baki sare X ban skte h

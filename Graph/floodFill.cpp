class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int drow[], int dcol[], int iniColor){
        int n = image.size();
        int m = image[0].size();
        //mark it with the given color
        ans[sr][sc] = color;
        //check all neighbours
        for (int i = 0; i < 4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            //cehck validity + should have iniColor + have not been visited before, means not of color
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != color){
                    //apply dfs
                    dfs(nrow, ncol, ans, image, color, drow, dcol, iniColor);
                } 
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //store initial color 
        int iniColor = image[sr][sc];
        //copy image
        vector<vector<int>> ans = image;
        //neighbours: up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        //call dfs
        dfs(sr, sc, ans, image, color, drow, dcol, iniColor);
        return ans;
    }
};

//start node se dfs call kra, vo neighbour chekc krke aage chlta jaega
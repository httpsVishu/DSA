class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n-1;
        while (top < down){
            if (mat[top][down] == 1){ //mtlb top knows down then top cant be celeb
                top++; //top ko aage le jao
            }
            else if (mat[down][top] == 1){ // mltnb agar down knows top then down cant be celeb
                down--; //down ko piche le aao
            }
            else{
                //is point pe dono 0 honge, then none of them can be celeb
                // as agar ek nhi janta to dusre ko jan na jruri h h
                top++;
                down--;
            }
        }
        
        //agar top bottom se bda ho jaye
        if (top > down) return -1; //means no celeb
        
        //now we stand at point where top == bottom
        //check if all row element are 0 and col eleemnt as 1 except diagonal one
        for (int i = 0; i < n; i++){
            if (i == top) continue; //skip diagonal
            if (mat[top][i] == 0 && mat[i][top] == 1){
                //
            }
            else{
                return -1; //not a celeb
            }
        }
        return top; //or down
    }
};
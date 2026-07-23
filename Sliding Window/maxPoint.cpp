class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //phle first k elemnts ka sum nikalo 
        //then 1 aage se gahate rho and 1 piche se add krte jao
        int lsum = 0, rsum = 0, maxSum = 0;
        for (int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        //initially maxSum lsum ke equal hoga
        maxSum = lsum;
        // ab k-1 se ghatate rho and n-1 se add krt rho
        int rIndex = cardPoints.size() - 1;
        for (int i = k-1; i >= 0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rIndex];
            rIndex--;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};
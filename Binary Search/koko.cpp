class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high){
            int mid = low + (high - low)/2;
            int totalHrs = calcTotalHours(piles, mid);
            if (totalHrs <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    int calcTotalHours(vector<int>& arr, int hourly){
        int totalH = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            totalH += ceil((double)arr[i]/(double)hourly);
        }
        return totalH;
    }
};
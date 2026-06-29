class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high){
            int mid = (low + high)/2;
            int val = calcDays(weights, mid);
            if (val <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    int calcDays(vector<int>& wt, int cap){
        int day = 1;
        int load = 0;
        for (int i = 0; i < wt.size(); i++){
            if (load + wt[i] > cap){
                day += 1;
                load = wt[i];
            }
            else{
                load += wt[i];
            }
        }
        return day;
    }
};
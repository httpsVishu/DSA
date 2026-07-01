class Solution {
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if (n <= 1) return 0.0;
        vector<int> howMany(n-1, 0);
        priority_queue<pair<double, int>> pq;
        
        for (int i = 0; i < n-1; i++){
            pq.push({arr[i+1]-arr[i], i});
        }
        
        for (int gs = 1; gs <=k; gs++){
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            
            double iniDiff = arr[secInd + 1] - arr[secInd];
            double secLength = iniDiff/(double)(howMany[secInd] + 1);
            
            pq.push({secLength, secInd});
        }
        
        return pq.top().first;
    }
};
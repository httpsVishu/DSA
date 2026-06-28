class Solution {
    public:
        int nthRoot(int n, int m) {
            if (n == 0) return 0;
            if (m == 0 || n == 1) return m;
            int low = 1;
            int high = m;
            while (low <= high){
                int mid = low + (high - low)/2;
                int val = func(mid, n, m);
                if (val == 1) return mid;
                else if (val == 0) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        }
        
        int func(int mid, int n, int m){
            long long ans = 1;
            for (int i = 1; i <=n; i++){
                ans = ans*mid;
                if (ans > m) return 2;  //kisi pe point pe m se jyada ho jaye to aage calc karne ka fayda nahi
            }
            if (ans == m) return 1;
            return 0;
        }
};
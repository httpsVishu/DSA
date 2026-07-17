class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> list; //max element will be n-k+1 in list, no need to initilaise the size, else push_back will push after 0
        deque<int> dq;
        //left to right traverse krna h
        for (int i = 0; i < n; i++){
            //agar dq me element ho and uska front element ith se k kam ho mltb vo window se bahar h
            //henec pop that front el

            //kind of maintaining monotonic stack

            //e.g. 5-3 = 2, hence 2 index wale ko pop krdena
            while (!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            //since we need to find max, top el chota ni hona chaiye, if chota h to pop kro
            //equal bhi ni hona chaiye coz no use
            while (!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back(); //pop krdo
            }

            dq.push_back(i); //naye index ko push krdo

            //first max kth distance pe milegfa hence jb i = k-1 ho jaye, tb se push krna shuru krna

            if (i >= k-1) list.push_back(arr[dq.front()]);
            //since montonic in max fashion, front will be max
        }
        return list;
    }
};
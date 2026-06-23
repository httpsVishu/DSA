class Solution {
  public:
  void merge(vector<int>& arr, int low, int mid, int high){
      vector<int> temp;
      int left = low;
      int right = mid + 1;
      
      while ((left <= mid) && (right <= high)){
          if (arr[left] <= arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          else{
              temp.push_back(arr[right]);
              right++;
          }
      }
      
      while (left <= mid){
          temp.push_back(arr[left]);
          left++;
      }
      
      while (right <= high){
          temp.push_back(arr[right]);
          right++;
      }
      
      for (int i = low; i <= high; i++){
          arr[i] = temp[i - low];
      }
  }

  int countPairs(vector<int>& arr, int low, int mid, int high){
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++){
        while ((right <= high) && ((long long)arr[i] > (long long)2*arr[right])){
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
  }
  
  int mergeSort(vector<int>& a, int low, int high){
      int cnt = 0;
      if (low >= high) return 0;
      int mid = (low + high)/2;
      cnt += mergeSort(a, low, mid);
      cnt += mergeSort(a, mid+1, high);
      cnt += countPairs(a, low, mid, high);
      merge(a, low, mid, high);
      return cnt;
  }
  
  int reversePairs(vector<int>& arr){
    return mergeSort(arr, 0, arr.size()-1);
  }
};
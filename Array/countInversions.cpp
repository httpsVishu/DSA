class Solution {
  public:
  long long merge(vector<int>& arr, int low, int mid, int high){
      vector<int> temp;
      int left = low;
      int right = mid + 1;
      long long cnt = 0;
      
      while ((left <= mid) && (right <= high)){
          if (arr[left] <= arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          else{
              temp.push_back(arr[right]);
              cnt += (mid - left) + 1;
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
      
      return cnt;
  }
  
  long long mergeSort(vector<int>& a, int low, int high){
      long long cnt = 0;
      if (low >= high) return 0;
      int mid = (low + high)/2;
      cnt += mergeSort(a, low, mid);
      cnt += mergeSort(a, mid+1, high);
      cnt += merge(a, low, mid, high);
      return cnt;
  }
  
  long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};
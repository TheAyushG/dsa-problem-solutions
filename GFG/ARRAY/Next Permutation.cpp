class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        
        int n = arr.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element
        while(i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        
        // Step 2: If such element exists, find next greater element
        if(i >= 0) {
            int j = n - 1;
            while(arr[j] <= arr[i]) {
                j--;
            }
            swap(arr[i], arr[j]);
        }
        
        // Step 3: Reverse the remaining part
        reverse(arr.begin() + i + 1, arr.end());
    }
};

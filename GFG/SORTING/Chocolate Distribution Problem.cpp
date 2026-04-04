class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        
        int n = arr.size();
        
        // Edge case
        if(m == 0 || n == 0) return 0;
        if(m > n) return -1;
        
        // Step 1: Sort
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        // Step 2: Sliding window of size m
        for(int i = 0; i + m - 1 < n; i++){
            
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};

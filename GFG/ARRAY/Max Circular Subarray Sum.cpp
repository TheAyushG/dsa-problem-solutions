------------------------------------------
Complexity	Value
Time	O(n)
Space	O(1)
------------------------------------------
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
      
        int n = arr.size();
        
        int totalSum = 0;
        int currMax = 0;
        int currmin = 0;
        
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        
        for(int i=0; i<n; i++){
            
           currMax = max(arr[i], currMax + arr[i]);
           maxSum = max(currMax, maxSum);
           
           currmin = min(arr[i], currmin + arr[i]);
           minSum = min(currmin, minSum);
           
           totalSum += arr[i];
        }
        
        if(maxSum < 0){
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};






------------------------------------------
Brute Force
Time: O(n²)
Space: O(1)
------------------------------------------
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        int maxSum = INT_MIN;
        
        for(int i=0; i<n; i++){
            int currSum = 0;
            
            for(int j=0; j<n; j++){
                
                int idx = (i+j) % n;
                currSum += arr[idx];
                
                maxSum = max(currSum, maxSum);
            }
        }
        
        return maxSum;
    }
};

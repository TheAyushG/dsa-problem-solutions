class Solution {
public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        int leftSum = 0;
        
        for(int i = 0; i < n; i++) {
            int rightSum = totalSum - arr[i] - leftSum;
            
            if(leftSum == rightSum) {
                return i;
            }
            
            leftSum += arr[i];
        }
        
        return -1;
    }
};

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        
        int n = arr.size();
        
        // Step 1: remove useless values
        for(int i = 0; i < n; i++){
            if(arr[i] <= 0 || arr[i] > n){
                arr[i] = n + 1;
            }
        }
        
        // Step 2: mark presence
        for(int i = 0; i < n; i++){
            int index = abs(arr[i]) - 1;
            
            if(index < n && arr[index] > 0){
                arr[index] *= -1;
            }
        }
        
        // Step 3: find missing
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

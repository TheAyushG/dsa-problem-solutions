class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int gola_index = -1;
        
        for(int i=n-1; i > 0; i--){
            if(arr[i] > arr[i-1]){
                gola_index = i-1;
                break;
            }
        }
        
        if(gola_index != -1){
            int swap_index = gola_index;
            
            for(int j=n-1; j>=gola_index+1; j--){
                if(arr[j] > arr[gola_index]){
                    swap_index = j;
                    break;
                }
            }
            
            swap(arr[gola_index], arr[swap_index]);
        }
        
        reverse(arr.begin() + gola_index + 1, arr.end());
    }
};

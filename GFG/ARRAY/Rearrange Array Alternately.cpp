----------------------------------------
Optimal Solution
----------------------------------------

class Solution{
public:
    void rearrange(vector<int> &arr) {
        
        int n = arr.size();
        
        // Step 1: sort
        sort(arr.begin(), arr.end());
        
        int max_idx = n - 1;
        int min_idx = 0;
        
        int maxElement = arr[n - 1] + 1;
        
        // Step 2: encode
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                arr[i] += (arr[max_idx] % maxElement) * maxElement;
                max_idx--;
            } else {
                arr[i] += (arr[min_idx] % maxElement) * maxElement;
                min_idx++;
            }
        }
        
        // Step 3: decode
        for(int i = 0; i < n; i++) {
            arr[i] = arr[i] / maxElement;
        }
    }
};



----------------------------------------
Brute Force
----------------------------------------
class Solution{
public:
    void rearrange(vector<int> &arr) {
        
        int n = arr.size();
        
        // Step 1: sort
        sort(arr.begin(), arr.end());
        
        vector<int> temp(n);
        
        int left = 0;
        int right = n - 1;
        
        // Step 2: fill temp array
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                temp[i] = arr[right--]; // max
            } else {
                temp[i] = arr[left++];  // min
            }
        }
        
        // Step 3: copy back
        for(int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

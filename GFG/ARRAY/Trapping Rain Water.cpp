Trapping Rain Water.cpp
----------------------------------------
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        int n = arr.size();
        
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while(left <= right){
            
            if(arr[left] <= arr[right]){
                
                if(arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    water += leftMax - arr[left];
                
                left++;
            }
            else{
                
                if(arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    water += rightMax - arr[right];
                
                right--;
            }
        }
        
        return water;
    }
};





----------------------------------------------------------

class Solution {
  public:
  
    vector<int> getLeftMaxArray(vector<int>& arr, int& n){
        vector<int> leftMax(n);
        
        leftMax[0] = arr[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        
        return leftMax;
    }
    
    vector<int> getrightMaxArray(vector<int>& arr, int& n){
        vector<int> rightMax(n);
        
        rightMax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        
        return rightMax;
    }
    
  
    int maxWater(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<int> leftMax  = getLeftMaxArray(arr, n);
        vector<int> rightMax = getrightMaxArray(arr, n);
        
        int sum = 0;
        
        for(int i=0; i<n; i++){
            int h = min(leftMax[i], rightMax[i]) - arr[i];
            
            sum += h;
        }
        
        return sum;
    }
};

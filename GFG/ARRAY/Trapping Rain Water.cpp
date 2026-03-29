Trapping Rain Water.cpp
-----------------------------------------------------------------------------------------------------------------------------------------------
Time: O(n) ✅
Space: O(1) ✅

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = n-1;
        int water = 0;

        while(left <= right){

            if(height[left] <= height[right]){

                if(height[left] >= leftMax){
                    leftMax = height[left];
                }

                else{
                    water +=  leftMax - height[left];
                }

                left++;
            }

            else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }

                else{
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};


-----------------------------------------------------------------------------------------------------------------------------------------------
Time: O(n) ✅
Space: O(n) ❌
  
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<int> leftMax(n), rightMax(n);
        
        // left max
        leftMax[0] = arr[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        
        // right max
        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        
        int water = 0;
        
        for(int i = 0; i < n; i++){
            water += min(leftMax[i], rightMax[i]) - arr[i];
        }
        
        return water;
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------

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

----------------------------------------------------------------------------------------------------------------

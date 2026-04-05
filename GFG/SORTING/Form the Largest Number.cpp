class Solution {
  public:
    
    static bool cmp(string a, string b){
        return a + b > b + a;
    }
    
    string findLargest(vector<int> &arr) {
        
        vector<string> nums;
        
        // Step 1: convert int → string
        for(int i = 0; i < arr.size(); i++){
            nums.push_back(to_string(arr[i]));
        }
        
        // Step 2: sort using custom comparator
        sort(nums.begin(), nums.end(), cmp);
        
        // Step 3: build result
        string result = "";
        for(int i = 0; i < nums.size(); i++){
            result += nums[i];
        }
        
        // Step 4: edge case
        if(result[0] == '0') return "0";
        
        return result;
    }
};

class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        
        
        unordered_map<int,int> map;
        
        int n = arr1.size();
        vector<pair<int,int>> result;
        
        for(int i=0; i<n; i++){
            map[arr1[i]]++;
        }
        
        for(int i=0; i<arr2.size(); i++){
            int diff = target - arr2[i];
            if(map.find(diff) != map.end()){
                int count = map[diff];
                
                while(count--) {
                    result.push_back({diff, arr2[i]});
                }
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
       
       int n = arr.size();
       sort(arr.begin(), arr.end());
       
       int i=0;
       int j=1;
       while(j<n){
           
        if(i == j){
            j++;
            continue;
        }
           
        if(arr[j] - arr[i] == x)
            return true;
           
        else if(arr[j] - arr[i] < x){
            j++;
        }
           
        else if(arr[j] - arr[i] > x){
            i++;
        }
           
       }
       
       return false;
    }
};

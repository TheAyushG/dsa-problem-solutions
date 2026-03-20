-------------------------------------------
  optimal solution using map
-------------------------------------------

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

       int n = fruits.size();
       int maxLength = 0;

       unordered_map<int,int> map;

       int i=0;
       int j=0;

       while(j<n){

            map[fruits[j]]++;
            
            if(map.size() <= 2){
                maxLength = max(maxLength, j-i+1);
            }

            else{
                map[fruits[i]]--;
                if(map[fruits[i]] == 0){
                    map.erase(fruits[i]);
                    }
                i++;
            }
            j++;
       }
       
       return maxLength;
    }
};




--------------------------------------------------
Brute forces
--------------------------------------------------
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

       int n = fruits.size();
       int maxLength = 0;

       for(int i=0; i<n; i++){
            unordered_map<int, int> map;

            for(int j=i; j<n; j++){
                
                map[fruits[j]]++;

                if(map.size() > 2){
                    break;
                }
              
                maxLength = max(maxLength, j-i+1);
            }
       }

       return maxLength;
    }
};

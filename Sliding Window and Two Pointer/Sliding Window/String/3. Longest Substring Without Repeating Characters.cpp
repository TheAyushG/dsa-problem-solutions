-------------------------------------------
Using Hash 256
Time Complexity: O(n)
Space Complexity: O(256)
-------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxLen = 0;

        vector<int> hash(256, -1);
        int left = 0;

        for(int right=0; right<n; right++){

            if(hash[s[right]] != -1){
                left = max(left, hash[s[right]] + 1);
            }

            hash[s[right]] = right;
            maxLen = max(right-left+1, maxLen);
        }
        
        return maxLen;

    }
};;







-------------------------------------------
Using unordered map
Simple version
Time - O(n)
space - O(n)
-------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxLen = 0;
        unordered_map<char,int> map;

        int left = 0;

        for(int right=0; right<n; right++){

            while(map.find(s[right]) != map.end()){
                map.erase(s[left]);
                left++;
            }

            map[s[right]] = right;
            maxLen = max(right-left+1, maxLen);
        }
        
        return maxLen;

    }
};





  
  
-------------------------------------------
Using unordered set
Simple version
Time - O(n)
space - O(n)
-------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxLen = 0;
        unordered_set<char> st;

        int left = 0;

        for(int right=0; right<n; right++){

            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            maxLen = max(right-left+1, maxLen);
        }
        
        return maxLen;

    }
};







-------------------------------------------------
Brute Force Method
-------------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    int n = s.size();
    int maxLen = 0;

    for(int i=0; i<n; i++){
        vector<int> freq(256, 0);

        for(int j=i; j<n; j++){
            if(freq[s[j]] == 1){
                break;
            }

            freq[s[j]]++;
            maxLen = max(maxLen, j-i+1);
        }
    }

    return maxLen;

    }
};

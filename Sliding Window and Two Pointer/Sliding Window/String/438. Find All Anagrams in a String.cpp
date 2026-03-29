Time - O(n)
Space - O(1)
---------------------------------------------------
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> freqS(26, 0);
        vector<int> freqP(26, 0);
        vector<int> result;

        for(int i=0; i<m; i++){
            freqP[p[i] - 'a']++;
        }

        int i=0;
        int j=0;

        while(j < n){
            freqS[s[j] - 'a']++;

            if(j-i+1 == m){
                if(freqS == freqP){
                    result.push_back(i);
                }
            }

            if(j-i+1 >= m){
                freqS[s[i] - 'a']--;
                i++;
            }

            j++;
        }
        return result;
    }
};

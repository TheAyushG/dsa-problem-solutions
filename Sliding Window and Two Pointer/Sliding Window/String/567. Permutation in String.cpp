-----------------------------------------------
Time - O(m+n)
space - O(26)
-----------------------------------------------
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

     int n = s1.size();
     int m = s2.size();

     if(n > m){
        return false;
     } 

    vector<int> freqS1(26,0);
    vector<int> freqS2(26,0);

    for(char &ch : s1){
        freqS1[ch - 'a']++;
    }

    int i=0;
    int j=0;

    while(j < m){
        freqS2[s2[j] - 'a']++;

        if(j-i+1 > n){
            freqS2[s2[i] - 'a']--;
            i++;
        }

        if(freqS1 == freqS2){
            return true;
        }

        j++;
    }

    return false;
    }
};






---------------------------------------------------
Time - O((m-n)*nlogn)
space - O(1)
---------------------------------------------------
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m){

            return false;
        }         

        sort(begin(s1), end(s1));

        for(int i=0; i<=m-n; i++){
            string subString = s2.substr(i,n);

            sort(begin(subString), end(subString));

            if(s1 == subString){
                return true;
            }
        }
        return false;
  }
};

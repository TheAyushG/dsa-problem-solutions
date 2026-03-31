class Solution {
  public:
  
    long long func(long long firstHalf, bool isEven){
        long long resultNum = firstHalf;
        
        if(!isEven){ // odd length
            firstHalf /= 10;
        }
        
        while(firstHalf > 0){
            int digit = firstHalf % 10;
            resultNum = resultNum * 10 + digit;
            firstHalf /= 10;
        }
        
        return resultNum;
    }
  
  
    long long int closestPalindrome(long long int num) {
        
        string n = to_string(num);
        int L = n.length();
        
        int mid = L / 2;
        int firstHalfLength = (L % 2 == 0) ? mid : (mid + 1);
        
        long long firstHalf = stoll(n.substr(0, firstHalfLength));
        
        vector<long long> possibleResults;
        
        // main candidates
        possibleResults.push_back(func(firstHalf, L % 2 == 0));
        possibleResults.push_back(func(firstHalf + 1, L % 2 == 0));
        possibleResults.push_back(func(firstHalf - 1, L % 2 == 0));
        
        // edge cases
        possibleResults.push_back((long long)pow(10, L - 1) - 1); // 999...
        possibleResults.push_back((long long)pow(10, L) + 1);     // 100...001
        
        long long diff = LLONG_MAX;
        long long result = LLONG_MAX;
        long long originalNum = num;
        
        for(long long x : possibleResults){
            
            long long currDiff = abs(x - originalNum);
            
            // ✅ IMPORTANT: allow same number also
            if(currDiff < diff){
                diff = currDiff;
                result = x;
            }
            else if(currDiff == diff){
                result = min(result, x);
            }
        }
        
        return result;
    }
};

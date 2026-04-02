class Solution {
  public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        
        vector<pair<pair<int,int>, int>> meetings;
        
        for(int i = 0; i < N; i++){
            meetings.push_back({{F[i], S[i]}, i + 1});
        }
        
        sort(meetings.begin(), meetings.end());
        
        vector<int> result;
        
        result.push_back(meetings[0].second);
        int lastEnd = meetings[0].first.first;
        
        for(int i = 1; i < N; i++){
            
            int start = meetings[i].first.second;
            int end   = meetings[i].first.first;
            
            if(start > lastEnd){
                result.push_back(meetings[i].second);
                lastEnd = end;
            }
        }
        
        // ✅ IMPORTANT FIX
        sort(result.begin(), result.end());
        
        return result;
    }
};

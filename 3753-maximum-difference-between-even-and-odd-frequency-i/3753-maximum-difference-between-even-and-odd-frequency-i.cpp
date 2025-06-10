class Solution {
public:
    int maxDifference(string s) {
         vector<int> freq(26, 0);
        
   
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int mo = INT_MIN;
        int me = INT_MAX;
        
        for (int count : freq) {
            if (count == 0) continue;
            
            if (count % 2 == 1) {
                if (count > mo) {
                    mo = count;
                }
            } else {
                if (count < me) {
                    me= count;
                }
            }
        }
        
        return mo-me;
    }
};
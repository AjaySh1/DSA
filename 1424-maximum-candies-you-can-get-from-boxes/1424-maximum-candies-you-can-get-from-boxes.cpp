class Solution {
public:
   int maxCandies(vector<int>& s, vector<int>& c, vector<vector<int>>& k,
                   vector<vector<int>>& b, vector<int>& iB) {
        
        int n = s.size(), ans = 0;
        vector<bool> hK(n, false), hB(n, false), o(n, false);
        queue<int> q;
        
        for (int x : iB) {
            hB[x] = true;
            if (s[x]) q.push(x);
        }
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (o[x]) continue;
            o[x] = true;
            ans += c[x];
            
            for (int y : k[x]) {
                hK[y] = true;
                if (hB[y] && !o[y]) q.push(y);
            }
            
            for (int y : b[x]) {
                hB[y] = true;
                if (s[y] || hK[y]) q.push(y);
            }
        }
        
        return ans;
    }
};
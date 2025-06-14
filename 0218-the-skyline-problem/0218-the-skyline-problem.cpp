class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                        greater<pair<int, int>>> pq;
        for (auto it : build) {
            pq.push({it[0], -it[2]});
            pq.push({it[1], it[2]});
        }
        set<int, greater<int>> s;
        map<int, int> mp;
        vector<vector<int>> v;
        int prev = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int h = abs(it.second);
            int x = it.first;
            if (s.empty()) {
                vector<int> cur;
                cur.push_back(x);
                cur.push_back(h);
                v.push_back(cur);
                s.insert(h);
                mp[h]++;
                continue;
            }
            if (it.second < 0) {
                int top = *s.begin();
                if (h > top) {
                    vector<int> cur;
                    cur.push_back(x);
                    cur.push_back(h);
                    v.push_back(cur);
                }
                s.insert(h);
                mp[h]++;
            } else {
                mp[h]--;
                if (mp[h] == 0) {
                    
                    if(*s.begin()==h)
                    {
                        s.erase(h);
                    vector<int> cur;
                    cur.push_back(x);
                    cur.push_back((s.empty() ? 0 : *s.begin()));
                    v.push_back(cur);
                    continue;
                    }
                    else
                    {
                        s.erase(h);
                    }
                }
            }
        }
      return v;
    }
};
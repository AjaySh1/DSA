class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        int i=0;
         unordered_map<char, int> mp;
        for (char it : s) {
            mp[it]++;
        }

        stack<char> st;
        string cur;
        char prev = 'a';
        for (int i=0;i<n;i++) {
           st.push(s[i]);
            mp[s[i]]--;
            while (prev!= 'z' && mp[prev] == 0) {
                prev++;
            }
            while (!st.empty() && st.top() <=prev) {
                cur.push_back(st.top());
                st.pop();
            }
        }

        return cur;
    }
};
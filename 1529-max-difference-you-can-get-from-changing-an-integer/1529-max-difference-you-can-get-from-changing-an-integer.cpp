class Solution {
public:
    int maxDiff(int n) {
           string s = to_string(n), a = s, b = s;
        char x = '\0';
        for (char c : s) {
            if (c != '9') {
                x = c;
                break;
            }
        }
        if (x != '\0') {
            for (char &c : a) {
                if (c == x) c = '9';
            }
        }

        if (s[0] != '1') {
            x = s[0];
            for (char &c : b) {
                if (c == x) c = '1';
            }
        } else {
            x = '\0';
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    x = s[i];
                    break;
                }
            }
            if (x != '\0') {
                for (int i = 1; i < b.size(); i++) {
                    if (b[i] == x) b[i] = '0';
                }
            }
        }

        int m1 = stoi(a);
        int m2 = stoi(b);
        return m1 - m2;
    }
};
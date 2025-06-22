class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
          vector<string> result;
    for (int i = 0; i < (int)s.size(); i += k) {
        string group = s.substr(i, k);
        if ((int)group.size() < k) {
            group.append(k - group.size(), fill);
        }
        result.push_back(group);
    }
    return result;
    }
};
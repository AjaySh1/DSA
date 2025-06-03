class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.size()!=t.size())
        return false;
        string res=s+s;
        return res.find(t)!=string::npos;
    }
};
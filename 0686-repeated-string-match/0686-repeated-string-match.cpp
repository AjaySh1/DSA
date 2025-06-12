class Solution {
public:
    void constructLps(string& pat, vector<int>& lps) {
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < pat.length()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {

                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool find(string cur,string b)
    {
      int n = cur.length();
        int m = b.length();

        vector<int> lps(m);
        vector<int> res;

        constructLps(b, lps);

        int i = 0;
        int j = 0;

        while (i < n) {

            if (cur[i] == b[j]) {
                i++;
                j++;
                if (j == m) {
                  
                   return true;
                }
            }

            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string cur = a;
        while (cur.size() < b.size()) {
            cur += a;
            count++;
        }
       if(find(cur,b))
       return count;
       if(find(cur+a,b))
       return count+1;
       return -1;
    }
};
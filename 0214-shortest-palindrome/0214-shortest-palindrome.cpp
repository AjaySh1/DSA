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
    int find(string cur,string b)
    {
      int n = cur.length();
        int m = b.length();

        vector<int> lps(m);
        vector<int> res;
        vector<int>ans(n,0);
        constructLps(b, lps);

        int i = 0;
        int j = 0;
        int mx=0;
        while (i < n) {

            if (cur[i] == b[j]) {
                
                
                i++;
                j++;
                ans[i-1]=j;
                if (j == m) {
                  
                  
                }
            }

            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
           
        }
        return ans[n-1];
    }
    string shortestPalindrome(string s) {
        if(s.empty())
        return s;
        string cur=s;
        reverse(s.begin(),s.end());
        int k=find(s,cur);
        cout<<k<<endl;
        return s.substr(0,cur.size()-k)+cur;

    }
};
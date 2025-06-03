class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),i=0,mx=0,cur=0;
         while(i<n)
         {
            if(s[i]=='(')
            cur++;
            else if(s[i]==')')
            cur--;
            mx=max(cur,mx);
            i++;
         }
         return mx;
    }
};
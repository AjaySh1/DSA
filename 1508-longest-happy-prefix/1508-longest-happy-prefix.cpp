class Solution {
public:
    string longestPrefix(string s) {
        int i=0,j=1;
        int n=s.size();
        vector<int>v(n,0);
        vector<int>v1(n,0);
        while(j<n)
        {
            if(s[i]==s[j])
            {
                if(i>0)
               v[j]+=v[j-1]+1;
               else
               v[j]=1;
               i++;
               j++;
            }
            else if(i==0)
            {
                j++;
            }
            else
            i=0;
        }
        i=n-1;
        j=n-2;
        while(j>=0)
        {
            if(s[i]==s[j])
            {
                if(i<n-1)
               v1[j]+=v1[j+1]+1;
               else
               v1[j]=1;
               i--;
               j--;
            }
            else if(i==n-1)
            {
                j--;
            }
            else
            i=n-1;
        }

        int mx=max(v[n-1],v1[0]);

        return s.substr(0,mx);
    }
};
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ans=0;
        int c0=0;
        for(int i=0;i<n;i++)
        {
            ans+=(s[i]-'0');
            c0+=(s[i]=='0');
        }
        int i=0;
        int j=n-1;
        int k1=0,k2=0;
        while(i<n&&s[i]=='1')
        i++,k1++;
        while(j>=0&&s[j]=='1')
        j--,k2++;
        int count=0,mx=0;
        while(i<=j)
        {
            if(s[i]=='0')
            {
                mx=max(mx,count);
                count=0;
            }
            else
            count++;
            i++;
        }
        mx=max(count,mx);
        stack<int>st1,st2;
        int ans2=0;
        int p0=0,p1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(p0==0)
                {
                    p1++;
                    continue;
                }
             if(!st1.empty()&&!st2.empty())
             {
                ans2=max(ans2,p0+st1.top()+ans);
             }
             st1.push(p0);
             p0=0;
             p1++;
            }
            else
            {
                p0++;
                if(p1==0)
                continue;
                st2.push(p1);
                p1=0;
            }
        }
      cout<<p0<<endl;
         if(!st1.empty()&&!st2.empty()&&p0)
             {
                ans2=max(ans2,p0+st1.top()+ans);
             }
      

        return max(ans,ans2);
      




    }
};
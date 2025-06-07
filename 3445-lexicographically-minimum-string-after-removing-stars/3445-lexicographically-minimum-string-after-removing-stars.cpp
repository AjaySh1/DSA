class Solution {
public:

    string clearStars(string s) {
        int n=s.size();
        map<char,priority_queue<int>>mp;
      
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                bool flag=false;
                char prev='a';
                while(prev<='z'&&flag==false)
                {
                    while(!mp[prev].empty()&&mp[prev].top()>i)
                    {
                        mp[prev].pop();
                    }
                    if(!mp[prev].empty())
                    {
                        s[mp[prev].top()]='#';
                        mp[prev].pop();
                        flag=true;
                    }
                    else
                    prev++;
                }
            }
            else
            mp[s[i]].push(i);
        }
        string ans="";
        for(auto it:s)
        {
            if(it!='*'&&it!='#')
            ans.push_back(it);
        }
        return ans;

    }
};
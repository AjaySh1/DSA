class Solution {
public:
    int maxSubstrings(string word) {
        map<char,set<int>>mp;
        int n=word.size();
        int i=n-1;
        while(i>=0)
        {
            mp[word[i]].insert(i);
            i--;
        }
        int count=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            mp[word[i]].erase(mp[word[i]].begin());
             {
                if(mp[word[i]].lower_bound(i+3)!=mp[word[i]].end())
                {
                    if(i>prev)
                    {
                        count++;
                        prev=*mp[word[i]].lower_bound(i+3);
                    }
                    else
                    {
                        prev=min(prev,*mp[word[i]].lower_bound(i+3));
                    }
                }
             }
             
        }
      return count;
    }
};
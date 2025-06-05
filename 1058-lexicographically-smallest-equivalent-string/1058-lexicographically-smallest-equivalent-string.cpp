class Solution {
public:
 class dsfind
 {
    vector<int>par;
    public:
    dsfind(int n)
    {
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    int find(int x)
    {
          if(x==par[x])
          return x;
          return par[x]=find(par[x]);
    }
    void unionf(int a,int b)
    {
       int x=find(a),y=find(b);
       if(x>y)
       {
        par[x]=y;
       }
       else
       {
        par[y]=x;
       }
    }

 };
    string smallestEquivalentString(string s1, string s2, string b) {
        dsfind ds(26);
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            ds.unionf(s1[i]-'a',s2[i]-'a');
        }
        string s;
        for(auto it:b)
        {
            s.push_back('a'+ds.find(int(it-'a')));
        }
        return s;
    }
};
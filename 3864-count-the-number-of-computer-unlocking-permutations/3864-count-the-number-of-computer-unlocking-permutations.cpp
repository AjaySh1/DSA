class Solution {
public:
    int countPermutations(vector<int>& c) {
      
        int n=c.size();
          if(n==1)
        return 1;
        int mod=1e9+7;
        map<int,int>mp;
        vector<pair<int,int>>vp;
        for(int i=0;i<c.size();i++)
        {
            vp.push_back({c[i],i});
            mp[c[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>1||it.first!=c[0])
            {  cout<<"it.first "<<it.first<<endl;
                return 0;}
            else
            break;
        }
        sort(vp.begin(),vp.end());
       long long int ans=1ll;
        int i=0;
        int count=0;
        while(i<n)
        {
           if(i==0)
           {
            i++;
            count++;
            continue;
           }
           else
           {
            
                ans=((ans*1ll%mod)*(count*1ll%mod))%mod;
                i++;
                count++;
              
            
           }


        }
        return int(ans);
    }
};
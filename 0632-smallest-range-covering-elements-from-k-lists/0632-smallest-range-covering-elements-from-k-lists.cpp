class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size(),n=nums[0].size();
        int left,right,ans=INT_MAX;
        int pointer=0;
        vector<int>ptr(n,0);
        set<pair<int,pair<int,int>>>pq1;
        set<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>>pq2;
        for(int i=0;i<k;i++)
        {
            pq1.insert({nums[i][0],{i,0}});
            pq2.insert({nums[i][0],{i,0}});
        }
        while(pointer<k&&pq1.size()>=k&&pq2.size()>=k)
         {
             int l=pq1.begin()->first;
             int r=pq2.begin()->first;
             int i=pq1.begin()->second.first;
             int j=pq1.begin()->second.second;

             if((r-l)<ans)
             {
                left=l;
                right=r;
                ans=r-l;              
             }
             else if((r-l)==ans)
             {
                if(l<left)
                {
                    left=l;
                    right=r;
                }
             }
             pq1.erase({nums[i][j],{i,j}});
             pq2.erase({nums[i][j],{i,j}});
             if(j==nums[i].size()-1)
               pointer++;
             else if(j<nums[i].size()-1)
            { 
            pq1.insert({nums[i][j+1],{i,j+1}});
             pq2.insert({nums[i][j+1],{i,j+1}});
            }
         }
         return {left,right};


    }
};
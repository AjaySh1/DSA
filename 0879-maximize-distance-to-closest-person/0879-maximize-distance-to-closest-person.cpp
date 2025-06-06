class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int mx=0;
        int prev=0;
        int count=0;
        bool flag=true;
        int first=0,last=0;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                if(flag)
                {
                    first=i;
                    flag=!flag;
                }
                last=i;
                    count++;
                    mx=max(i-prev,mx);
                    prev=i;
                
            }
        }
        
        if((prev==0||prev==n-1)&&count==1)
        return n-1;
         if(count==1)
         {
            return max(prev,n-1-prev);
         }
        return max({mx/2,first,n-1-last});
    }
};
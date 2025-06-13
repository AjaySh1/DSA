class Solution {
public:
    bool check(int mid,vector<int>&nums,int p)
    {  int n=nums.size();
        int count=0;
        int i=1;
        while(i<n)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                count++;
                i+=2;
            }
            else
            i++;
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
       int n=nums.size();
       if(n==1)
       return 0;
       sort(nums.begin(),nums.end());
       int low=0,high=nums[n-1]-nums[0];
       int ans=0;
       while(low<=high)
       {
        int mid=(low+high)/2;
        if(check(mid,nums,p))
        {
          ans=mid;
          high=mid-1;
        }
        else
        low=mid+1;
       }
       return ans;
    }
};
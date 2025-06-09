class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int count0=0;
        int count1=0;
        int mx1=INT_MAX,mx2=INT_MAX;
        vector<int>temp=nums;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==-1)
            {
                count0++;
                nums[i+1]=nums[i+1]+(-(nums[i+1]))*2;
            }
        }
        if(nums[nums.size()-1]==1)
        {
            mx1=count0;
        }
         for(int i=0;i<temp.size()-1;i++)
        {
            if(temp[i]==1)
            {
                count1++;
                temp[i+1]=temp[i+1]+(-(temp[i+1]))*2;
            }
        }
        if(temp[temp.size()-1]==-1)
        {
            mx2=count1;
        }
        int ans=min(mx1,mx2);
        return ans<=k;
    }
};
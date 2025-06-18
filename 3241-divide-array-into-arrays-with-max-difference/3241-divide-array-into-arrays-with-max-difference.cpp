class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>v;
        int i=0;
        while(i+3<=n)
        {
            vector<int>v1;
            if((nums[i+2]-nums[i])>k)
            return {};
            else
            {
                v.push_back({nums[i],nums[i+1],nums[i+2]});
                i+=3;
            }
        }
        return v;
    }
};
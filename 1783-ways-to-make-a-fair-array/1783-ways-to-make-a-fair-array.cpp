class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int oddright = 0, evenright = 0;
        int oddleft = 0, evenleft = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                evenright += nums[i];
            } else {
                oddright += nums[i];
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenright -= nums[i];
            } else {
                oddright -= nums[i];
            }
            if(oddleft+evenright==oddright+evenleft)
            count++;
            if (i % 2 == 0) {
                evenleft += nums[i];
            } else {
                oddleft += nums[i];
            }

        }
        return count;
    }
};
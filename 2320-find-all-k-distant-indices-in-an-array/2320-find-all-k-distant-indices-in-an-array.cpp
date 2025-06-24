class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> isKDist(n, false);

        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int left = max(0, j - k);
                int right = min(n - 1, j + k);
                for (int i = left; i <= right; ++i) {
                    isKDist[i] = true;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (isKDist[i])
                result.push_back(i);
        }

        return result;
    }
};
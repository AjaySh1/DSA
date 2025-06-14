class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> st;

        for (int i = 0; i < nums.size(); i++) {
            auto it = st.lower_bound((long long)nums[i] - t);
            if (it != st.end() && *it <= (long long)nums[i] + t) {
                return true;
            }

            st.insert(nums[i]);
            if (i >= k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};

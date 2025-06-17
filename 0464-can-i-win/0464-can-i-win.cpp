class Solution {
public:
    unordered_map<int, bool> dp;

    bool find(int mask, int mi, int dt) {
        if (dp.count(mask)) return dp[mask];

        for (int i = 1; i <= mi; i++) {
            int bit = 1 << (i - 1);
            if ((mask & bit) == 0) {
                if (i >= dt || !find(mask | bit, mi, dt - i)) {
                    return dp[mask] = true;
                }
            }
        }
        return dp[mask] = false;
    }

    bool canIWin(int mi, int dt) {
        int total = (mi * (mi + 1)) / 2;
        if (total < dt) return false;
        if (dt <= 0) return true;
        return find(0, mi, dt);
    }
};

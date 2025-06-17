class Solution {
public:
    int count = 0;

    void backtrack(int pos, int n, int used) {
        if (pos > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            int bit = 1 << (i - 1);
            if (!(used & bit) && (i % pos == 0 || pos % i == 0)) {
                backtrack(pos + 1, n, used | bit);
            }
        }
    }

    int countArrangement(int n) {
        count = 0;
        backtrack(1, n, 0);
        return count;
    }
};

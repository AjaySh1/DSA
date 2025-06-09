class Solution {
public:
       int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;
        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    long countSteps(int n, long first, long last) {
        long steps = 0;
        while (first <= n) {
            steps += min((long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }

};
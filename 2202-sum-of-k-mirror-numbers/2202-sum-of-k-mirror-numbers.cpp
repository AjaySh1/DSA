class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;

        for (int length = 1; count < n; ++length) {
            int start = pow(10, (length - 1) / 2);
            int end = pow(10, (length + 1) / 2);
            for (int i = start; i < end && count < n; ++i) {
                string left = to_string(i);
                string right = left;
                if (length % 2 == 1) right.pop_back();  
                reverse(right.begin(), right.end());
                string palStr = left + right;
                long long val = stoll(palStr);
                if (isPalindrome(toBaseK(val, k))) {
                    ans += val;
                    count++;
                }
            }
        }

        return ans;
    }

private:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string result;
        while (num > 0) {
            result += (char)((num % k) + '0');
            num /= k;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

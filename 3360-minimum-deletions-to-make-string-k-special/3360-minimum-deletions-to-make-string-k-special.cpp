class Solution {
public:
    int minimumDeletions(string word, int k) {
           unordered_map<char, int>mp;
    for (char c : word) {
        mp[c]++;
    }

    vector<int> freqs;
    for (auto &[ch, freq] : mp) {
        freqs.push_back(freq);
    }

    sort(freqs.begin(), freqs.end());
    int n = freqs.size();
    int minDeletions = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int target = freqs[i];
        int deletions = 0;

        for (int j = 0; j < i; ++j) {
            deletions += freqs[j];
        }

        for (int j = i + 1; j < n; ++j) {
            if (freqs[j] > target + k) {
                deletions += freqs[j] - (target + k);
            }
        }

        minDeletions = min(minDeletions, deletions);
    }

    return minDeletions;
    }
};
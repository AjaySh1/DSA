class Solution {
public:
    int mergeCount(vector<long>& sums, int low, int mid, int high, int lower, int upper) {
        int count = 0;
        int j = mid + 1, k = mid + 1, t = mid + 1;
        vector<long> temp;
        for (int i = low; i <= mid; i++) {
            while (j <= high && sums[j] - sums[i] < lower) j++; 
            while (k <= high && sums[k] - sums[i] <= upper) k++; 
            count += (k - j); 
        }
     
        vector<long> merged;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (sums[left] < sums[right]) {
                merged.push_back(sums[left]);
                left++;
            } else {
                merged.push_back(sums[right]);
                right++;
            }
        }
        
        while (left <= mid) {
            merged.push_back(sums[left]);
            left++;
        }
        
        while (right <= high) {
            merged.push_back(sums[right]);
            right++;
        }
        
        for (int i = low; i <= high; i++) {
            sums[i] = merged[i - low];
        }
        
        return count;
    }

    int mergeSortAndCount(vector<long>& sums, int low, int high, int lower, int upper) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int count = mergeSortAndCount(sums, low, mid, lower, upper) +
                    mergeSortAndCount(sums, mid + 1, high, lower, upper);
        count += mergeCount(sums, low, mid, high, lower, upper);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        
        
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        
        return mergeSortAndCount(sums, 0, n, lower, upper);
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<pair<int, int>>ans;

        for(int i = 0; i < m; i++) {
            int left = 0, right = mat[i].size(), mid;
            while(left < right) {
                mid = (left + right) / 2;
                if(mat[i][mid] == 1) left = mid + 1;
                else right = mid;
            }
            ans.push_back({left, i}); 
        }

        sort(ans.begin(), ans.end());
        vector<int> res;
        for(int i = 0; i < k; i++) 
        res.push_back(ans[i].second);
        return res;

    }
};
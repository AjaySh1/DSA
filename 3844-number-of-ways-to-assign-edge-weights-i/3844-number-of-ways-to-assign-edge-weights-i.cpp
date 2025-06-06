class Solution {
public:

  long long int solve(int pos, int parity, int n,vector<vector<long long int>>&dp) {
    if (pos == n) return parity == 1; 
    if (dp[pos][parity] != -1) return dp[pos][parity];

  long long int add1 = solve(pos + 1, (parity + 1) % 2, n,dp); 
  long long int add2 = solve(pos + 1, parity, n,dp);         

    return dp[pos][parity] = (add1 + add2)%(1000000007);
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> adj[n + 1];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        queue<int> q;
        q.push(1);
        vector<int> vis(n + 1, 0);
        vis[1]++;
        while (!q.empty()) {
            int size = q.size();
            count++;
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it]++;
                        q.push(it);
                    }
                }
            }
        }
        --count;
     
     cout<<count<<endl;
        vector<vector<long long int>>dp(count,vector<long long int>(2,-(1ll)));

        return solve(0,0,count,dp);
    }
};
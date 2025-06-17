#define mod 1000000007
class Solution {
public:
  int find(int n,int l,int c,vector<vector<vector<int>>>&dp)
  {
    if(n==0)
    return 1;
    if(dp[n][c][l]!= -1)
    return dp[n][c][l];
    int pick1=find(n-1,l,0,dp);
    int pick2=0;
    if(l==0)
    {
        pick2=find(n-1,1,0,dp);
    }
    int pick3=0;
    if(c<2)
    pick3=find(n-1,l,c+1,dp);
    return dp[n][c][l]=((pick1+pick2)%mod+pick3)%mod;
  }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return find(n,0,0,dp);
    }
};
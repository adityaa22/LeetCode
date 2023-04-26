class Solution {
public:
    int m,n;
    int ans=1005;
    int dp[201][201];
    int solve(vector<vector<int>>& v, int i,int j){
         if(i==m-1 && j==n-1){
            return dp[i][j]=min(0,v[i][j]);
         }
         if(i>=m || j>=n)return -1e7;
         if(dp[i][j]!=-1e6)return dp[i][j];
        
         dp[i][j]=min(0,v[i][j]+max(solve(v,i+1,j),solve(v,i,j+1)));
         return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& v) {
        m=v.size();
        n=v[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)dp[i][j]=-1e6;
        int x=solve(v,0,0);
        return abs(x)+1;
    }
};
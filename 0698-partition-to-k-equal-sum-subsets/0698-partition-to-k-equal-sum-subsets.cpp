class Solution {
public:
    int s, n;
    int solve(vector<int> &nums, vector<int>&dp, int mask, int sum, int k){
        if(k == 0){
            return mask == (1 << n) - 1;
        }
        
        if(sum == s){
            return solve(nums, dp, mask, 0, k - 1);
        }
     
        if(dp[mask] != -1) return dp[mask];

        int ans = false;
        for(int i = 0; i < n; i++){
            if((1<<i) & mask) continue;
            if(sum + nums[i] <= s){
                int newMask = mask | (1 << i);
                ans = ans || solve(nums,dp,newMask,sum + nums[i],k);
            }
        }
        return dp[mask] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        s = 0;
        n = nums.size();
        for(int i = 0; i < n; i++){
            s+= nums[i];
        }
        if(s%k != 0)return false;
        s /= k;
        vector<int> dp((1<<n),-1);
        return solve(nums,dp,0,0,k);
    }
};
class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int n){
        if(n < 0) {
            return 0;
        }
        if(n == 0) return nums[0];
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = solve(nums,dp,n-2) + nums[n];
        int notPick = solve(nums,dp,n-1);
        dp[n] = max(pick,notPick);
        return dp[n];

    }
    int rob(vector<int>& nums) { 
        int n = nums.size();
        vector<int> dp(n+1,-1);
        

        return solve(nums,dp,n-1);
    }
};

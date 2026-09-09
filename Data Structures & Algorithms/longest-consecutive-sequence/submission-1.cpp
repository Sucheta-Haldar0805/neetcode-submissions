class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int len = 1;
        int maxi = 1;

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i-1]) {
                continue;
            }

            if(nums[i] == nums[i-1] + 1) {
                len++;
            }
            else {
                len = 1;
            }

            maxi = max(maxi, len);
        }

        return maxi;
    }
};
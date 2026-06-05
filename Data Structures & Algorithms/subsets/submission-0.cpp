class Solution {
public:
    void calSubsets(vector<int> nums,vector<int>& subsets,vector<vector<int>>& ans){
        int n = nums.size();
        if(n == 0){
            ans.push_back(subsets);
            return;
        }
        //yes
        int x = nums[0];
        nums.erase(nums.begin());
        subsets.push_back(x);
        calSubsets(nums,subsets,ans);
        subsets.pop_back();
        //no
        calSubsets(nums,subsets,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsets;
        calSubsets(nums,subsets,ans);
        return ans;
    }
};

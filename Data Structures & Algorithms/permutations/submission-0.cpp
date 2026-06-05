class Solution {
public:
    void helper(vector<int>& nums,vector<int>& res,vector<vector<int>>& ans){
        int n = nums.size();
        if(n == 0){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<n;i++){
            vector<int> next = nums;
           
            next.erase(next.begin() + i);
            res.push_back(nums[i]);
            helper(next,res,ans);
            res.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(nums,res,ans);
        return ans;
    }
};

class Solution {
public:
    void printSubsets(vector<int>& nums,vector<int>& res, vector<vector<int>>& ans,int i){
        if(i == nums.size()){
            ans.push_back(res);
            return;
        }
        

        //include
        res.push_back(nums[i]);
        printSubsets(nums,res,ans,i+1);
        res.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        printSubsets(nums,res,ans,idx);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        printSubsets(nums,res,ans,0);
        return ans;
    }
};

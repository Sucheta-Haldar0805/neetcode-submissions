class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& candidates, int target, vector<int>& combn,int idx,vector<vector<int>>& ans){
        if(idx == candidates.size() || target < 0){
            return;
        }
        if(target == 0){
            if(s.find(combn) == s.end()){
                ans.push_back(combn);
                s.insert(combn);
            }
            return;
        }

        //include
        combn.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],combn,idx+1,ans);
        
        solve(candidates,target-candidates[idx],combn,idx,ans);
        combn.pop_back();

        //exclude
        solve(candidates,target,combn,idx+1,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combn;
        solve(candidates,target,combn,0,ans);
        return ans;
    }
};
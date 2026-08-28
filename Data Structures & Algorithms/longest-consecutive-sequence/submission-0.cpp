class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin(),nums.end());
        int cnt = 1;
        int maxi = 1;

        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }else if(nums[i] == nums[i+1]){
                continue;
            }else{
                cnt = 1;
            }
        }
        return maxi;
    }
};

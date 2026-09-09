class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi = 1;
        for(int x : s){
            if(s.find(x-1) == s.end()){
                int curr = x;
                int len = 1;

                while(s.find(curr+1) != s.end()){
                    curr++;
                    len++;
                }
                maxi = max(maxi,len);
            }
        }
        return maxi;
    }
};

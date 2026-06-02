class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<pair<int,int>> arr;
        for(const auto& x : freq){
            arr.push_back({x.second,x.first});
        }
        sort(arr.rbegin(),arr.rend());

        for(int i=0;i<k;i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(auto& s : strs){
            vector<int> freq(26,0);
            for(char ch : s){
                freq[ch-'a']++;
            }

            string k = to_string(freq[0]);
            for(int i=1;i<26;i++){
                k += "," + to_string(freq[i]);
            }

            mpp[k].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

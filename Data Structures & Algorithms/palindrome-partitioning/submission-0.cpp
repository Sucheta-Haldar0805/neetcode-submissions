class Solution {
public:
    bool isPalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());

        return s==s2;
    }
    void solve(string s,vector<vector<string>>& ans,vector<string>& part){
        int n = s.size();
        if(n == 0){
            ans.push_back({part});
            return;
        }

        for(int i=0;i<n;i++){
            string partition = s.substr(0,i+1);
            
            if(isPalindrome(partition)){
                part.push_back(partition);
                solve(s.substr(i+1),ans,part);
                part.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        solve(s,ans,part);
        return ans;
    }
};

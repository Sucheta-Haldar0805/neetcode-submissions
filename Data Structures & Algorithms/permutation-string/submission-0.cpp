class Solution {
public:
    bool isSame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        
        int windLength = s1.length();

        for(int i=0;i<s2.length();i++){
            int windFreq[26] = {0};
            int windIdx = 0;
            int idx = i;
            while(idx < s2.length() && windIdx < windLength){
                windFreq[s2[idx] - 'a']++;
                idx++;
                windIdx++;
            }
            if(isSame(freq,windFreq)){
                return true;
            }
        }

        
        return false;
    }
};

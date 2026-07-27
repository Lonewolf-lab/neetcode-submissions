class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0,r=0,maxLen = 0, maxFreq = 0;
        unordered_map<char, int> mp;

        while(r < n){
            mp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mp[s[r] - 'A']);
            int len = r-l+1;
            if(len - maxFreq > k){
                mp[s[l] - 'A']--;
                l++;
            }
            if(len - maxFreq <= k){
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};
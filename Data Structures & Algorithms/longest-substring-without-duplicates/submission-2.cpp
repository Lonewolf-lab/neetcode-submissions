class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l=0,r=0,maxLength = 0;

        while(r < n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            int len = r-l+1;
            maxLength = max(len, maxLength);
            r++;
        }
        return maxLength;
    }
};
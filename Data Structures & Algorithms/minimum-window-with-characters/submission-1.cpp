class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n < m) return ""; 

        int l = 0,r = 0;
        int minWindowSize = INT_MAX, start_l = 0;
        unordered_map<char, int> mp;

        for(char  &ch : t){
            mp[ch]++;
        }

        while(r < n){
            char  ch = s[r];

            if(mp[ch] > 0){
                m--;
            }

            mp[ch]--;

            while(m == 0){
                int currWindowSize = r-l+1;

                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    start_l = l;
                }
                
                mp[s[l]]++;

                if(mp[s[l]] > 0){
                    m++;
                }
                l++;
            }
            r++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_l, minWindowSize);
    }
};
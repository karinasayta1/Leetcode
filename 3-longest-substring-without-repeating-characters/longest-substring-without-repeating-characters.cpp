class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using sw and 2 pointers and hashmap

        unordered_map<char, int> mp;
        int l = 0, max_len = 0;

        for(int r  = 0 ; r<s.length(); r++){
            mp[s[r]]++;

            // if duplicate found
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
             max_len = max(max_len, r - l + 1);
        }
       return max_len;
    }
};
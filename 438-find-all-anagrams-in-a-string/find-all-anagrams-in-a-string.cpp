class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size())
            return ans;

        vector<int> shash(26, 0), phash(26, 0);

        int window = p.size();

        // Build frequency of p
        for(char c : p)
            phash[c - 'a']++;

        for(int i = 0; i < s.size(); i++) {

            // Add new character to window
            shash[s[i] - 'a']++;

            // Remove character if window too big
            if(i >= window)
                shash[s[i - window] - 'a']--;

            // If window size reached
            if(i >= window - 1) {
                if(shash == phash)
                    ans.push_back(i - window + 1);
            }
        }

        return ans;
    }
};

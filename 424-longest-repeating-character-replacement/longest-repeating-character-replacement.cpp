class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        
        int left = 0;
        int max_freq = 0;
        int count = 0;

        for(int right = 0; right < s.length(); right++) {
            
            // increase frequency
            freq[s[right] - 'A']++;

            // update max frequency
            max_freq = max(max_freq, freq[s[right] - 'A']);

            int win_size = right - left + 1;

            // if invalid, shrink window
            if(win_size - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // update answer
            count = max(count, right - left + 1);
        }

        return count;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
       if (s.size() < t.size()) return "";

        vector<int> freq(256, 0);

        // store frequency of t
        for (char c : t)
            freq[c]++;

        int left = 0, count = t.size();
        int minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {

            // if current char is needed
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;

            // when window becomes valid
            while (count == 0) {

                // update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                // if removing breaks validity
                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


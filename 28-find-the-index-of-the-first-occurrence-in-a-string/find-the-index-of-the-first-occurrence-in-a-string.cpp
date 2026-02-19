class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        if(m == 0) return 0;

        for(int i = 0; i <= n - m; i++) {

            int j = 0;

            // check match starting from i
            while(j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // if full match found
            if(j == m) {
                return i;
            }
        }

        return -1;
    }
};

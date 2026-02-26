class Solution {
public:
    string smallestSubsequence(string s) {
                vector<int> last(26);
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<bool> used(26, false);
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            
            char ch = s[i];
            
            if(used[ch - 'a']) continue;
            
            while(!st.empty() &&
                  ch < st.top() &&
                  last[st.top() - 'a'] > i) {
                
                used[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(ch);
            used[ch - 'a'] = true;
        }
        
        string result = "";
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;

    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> last(26,0);
       stack<char> st;
       vector<bool> used(26, false);

       for(int i = 0; i<s.size(); i++){
            last[s[i] - 'a'] = i;
       }

        for(int i = 0; i < s.size(); i++){

            char ch = s[i];
            if(used[ch - 'a']) continue;

            while(!st.empty() && ch<st.top()  && last[st.top()  - 'a'] > i){
                used[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            used[st.top()-'a'] = true;  
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
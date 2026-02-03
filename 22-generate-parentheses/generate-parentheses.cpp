class Solution {
public:
    void buildparanthesis(int n, int open_count, int close_count, string current, vector<string>& result){

        if(current.length() == 2*n){
            result.push_back(current);
            return;
        }

        if(open_count<n){
            buildparanthesis(n, open_count+1, close_count, current+"(", result);
        }

        if(close_count<open_count){
            buildparanthesis(n, open_count, close_count+1, current+")", result);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        buildparanthesis(n, 0, 0,"", ans);
        return ans;
    }
};
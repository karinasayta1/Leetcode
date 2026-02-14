class Solution {
public:
    void helper(string s, int index, int parts, string current, vector<string> & result){

        if(parts == 4 && index==s.length()){
            current.pop_back();
            result.push_back(current);
            return;
        }

        if(parts==4 || index == s.length())
            return;

        for(int len =1 ; len<=3; len++){
            if(index + len > s.length())
                break;

            string part = s.substr(index, len);

            if(part.length()>1 && part[0]=='0')
                continue;

            int num = stoi(part);
            if(num>255){
                continue;
            }

            helper(s, index+len, parts+1, current+part+".", result);
        }

        
    }
    vector<string> restoreIpAddresses(string s) {

     string current;
     vector<string>result;

     helper(s, 0, 0, current, result);
     return result;   
    }
};
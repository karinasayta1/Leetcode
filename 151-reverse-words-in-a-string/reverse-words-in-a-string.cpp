class Solution {
public:
    string reverseWords(string s) {
       int i = 0;
       int n = s.size();
       vector<string> words;
       while(i<n){

            while(i<n && s[i]==' '){
                i++;
            }

            if(i>=n) break;

            string word = "";

            while(i<n && s[i]!= ' ') {
                word += s[i];
                i++;
            }
            words.push_back(word);
       } 
        
       string result = "";
       for(int i = words.size()-1; i>=0; i--){
            result += words[i];
            if (i != 0)
            result += " ";
            
       }

    return result;

    }
};
class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long ans = -1;
       while(s<=e){
        long long m = s + (e-s)/2;
        long long  sq = m * m;

        if(sq == x){
            ans = m;
            return m;
        }
        else if(sq<=x){
            
            ans = m;
            s = m+1;
        }
        else{
            e = m - 1;
        }
       }
       return ans;
    }
};
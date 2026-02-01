class Solution {
public:

    int fact(int n){
        int res = 1;
        for(int i = 1; i<=n; i++){
            res *= i;
        }
        return res;
    }


    string getPermutation(int n, int k) {
     vector<int> nums;

     for(int i =1; i<=n; i++){
        nums.push_back(i);
     }   

     string result;
     k = k-1;
     while(!nums.empty()){

        int blocksize = fact(nums.size()-1);

        int index = k / blocksize ;

        result += to_string(nums[index]);

        nums.erase(nums.begin()+index);

        k= k% blocksize;

     }

    return result;
    }
};
class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        
        multiset<int> st;

        // take k strongest workers
        for(int i = workers.size() - mid; i < workers.size(); i++){
            st.insert(workers[i]);
        }

        int pillsused = 0;

        for(int i = mid - 1; i >= 0; i--){
            
            int reqstrength = tasks[i];

            auto it = prev(st.end()); // strongest worker

            if(*it >= reqstrength){
                st.erase(it);
            }
            else{
                if(pillsused >= pills) return false;

                auto weakestworkerIt = st.lower_bound(reqstrength - strength);

                if(weakestworkerIt == st.end()) return false;

                st.erase(weakestworkerIt);
                pillsused++;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0;
        int r = min(tasks.size(), workers.size());
        int result = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return result;
    }
};
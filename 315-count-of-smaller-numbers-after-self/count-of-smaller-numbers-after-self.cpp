class Solution {
public:

    void merge(vector<int>& nums, vector<int>& index, vector<int>& count, int start, int mid, int end) {
        vector<int> temp;
        int i = start, j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= end) {
            if (nums[index[i]] <= nums[index[j]]) {
                count[index[i]] += rightSmaller;
                temp.push_back(index[i]);
                i++;
            } else {
                rightSmaller++;
                temp.push_back(index[j]);
                j++;
            }
        }

        while (i <= mid) {
            count[index[i]] += rightSmaller;
            temp.push_back(index[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(index[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            index[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, vector<int>& index, vector<int>& count, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(nums, index, count, start, mid);
        mergeSort(nums, index, count, mid + 1, end);
        merge(nums, index, count, start, mid, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<int> index(n);

        for (int i = 0; i < n; i++) index[i] = i;

        mergeSort(nums, index, count, 0, n - 1);
        return count;
    }
};

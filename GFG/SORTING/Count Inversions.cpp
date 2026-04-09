class Solution {
public:
    long long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long count = 0;

        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                count += (mid - left + 1); // inversion
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {
        long long count = 0;
        if(low >= high) return count;

        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

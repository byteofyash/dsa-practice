// Last updated: 7/21/2026, 6:27:10 PM
class Solution {
    long long revPairCount = 0;
    void merge(vector<int>& arr, int low, int mid, int high) {

        vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

        int p1 = 0, p2 = 0;
        while (p1 < left.size() && p2 < right.size()) {
            if ((long long)left[p1] > 2 * 1LL * right[p2]) {
                revPairCount += (left.size() - p1);
                p2++;
            } else {
                p1++;
            }
        }

        int i = 0, j = 0;
        int k = low; // starting index of merged array
        while (i < left.size() && j < right.size()) {

            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {

                arr[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            arr[k++] = left[i++];
        }

        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

public:
    int reversePairs(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        mergeSort(arr, low, high);
        return revPairCount;
    }
};

// Last updated: 7/7/2026, 2:43:34 AM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        // bs on smaller array
        int low = 0;
        int high = m; // cause m+1 cuts are possible
        // | 1 2 3 OR 1 2 3 |

        while (low <= high) {
            int cutA = low + (high - low) / 2;
            int cutB = (m + n + 1) / 2 - cutA;

            int l1 = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int r1 = (cutA == m) ? INT_MAX : nums1[cutA];

            int l2 = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int r2 = (cutB == n) ? INT_MAX : nums2[cutB];

            if (l1 <= r2 && l2 <= r1) {
                if((((m+n) & 1))==1){
                    // odd
                    return max(l1, l2);
                }
                else{
                    // even
                    return ((double)max(l1, l2) + min(r1, r2)) / 2;

                    
                }
            }

            else if (l1 > r2) {
                // too many from A
                high = cutA - 1;
            } else {
                // l2> r1
                //  too few fromA
                low = cutA + 1;
            }
        }

        return 0.0;
    }
};
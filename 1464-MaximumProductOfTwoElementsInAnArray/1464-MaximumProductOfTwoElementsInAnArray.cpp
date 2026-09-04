// Last updated: 9/4/2026, 4:55:36 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0, secondLargest = 0;

        for (int num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest) {
                secondLargest = num;
            }
        }

        return (largest - 1) * (secondLargest - 1);
    }
};

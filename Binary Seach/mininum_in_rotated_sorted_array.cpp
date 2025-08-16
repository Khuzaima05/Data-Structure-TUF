// 🔗 LeetCode Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case 1: Left half is sorted
            if (v[low] <= v[mid]) {
                // Minimum could be v[low]
                ans = min(ans, v[low]);
                // Move to the right half
                low = mid + 1;
            }
            // Case 2: Right half is sorted
            else {
                // Minimum could be v[mid]
                ans = min(ans, v[mid]);
                // Move to the left half
                high = mid - 1;
            }
        }

        return ans;
    }
};

// LeetCode Problem: Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // ✅ Target found
            if (v[mid] == target)
                return true;

            // ⚠️ Handling duplicates: shrink the search space
            if (v[low] == v[mid] && v[mid] == v[high]) {
                low++;
                high--;
                continue;
            }

            // ✅ Left half is sorted
            if (v[low] <= v[mid]) {
                if (v[low] <= target && target <= v[mid])
                    high = mid - 1;  // Target lies in left half
                else
                    low = mid + 1;   // Target lies in right half
            }
            // ✅ Right half is sorted
            else {
                if (v[mid] <= target && target <= v[high])
                    low = mid + 1;   // Target lies in right half
                else
                    high = mid - 1;  // Target lies in left half
            }
        }

        return false; // Target not found
    }
};

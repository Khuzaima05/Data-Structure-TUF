/*
 * Title: Search in Rotated Sorted Array
 * Description:
 *   - Implements binary search in a rotated sorted array.
 *   - Uses the property that one half of the array is always sorted.
 *   - Time Complexity: O(log n)
 *   - Space Complexity: O(1)
 */



// LeetCode Problem: Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using namespace std;

// ===================================================
// Search in Rotated Sorted Array
// ---------------------------------------------------
// Idea:
// 1. The array is sorted but rotated at some pivot.
// 2. One half of the array (left or right) is always sorted.
// 3. Determine which half is sorted and check if target lies there.
// 4. Narrow search space accordingly.
// ===================================================

int search(vector<int>& v, int target) {
    int n = v.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Target found
        if (v[mid] == target)
            return mid;

        // Check if left half is sorted
        if (v[mid] >= v[low]) {
            if (target >= v[low] && target <= v[mid])
                high = mid - 1; // Target lies in left half
            else
                low = mid + 1;  // Target lies in right half
        }
        // Otherwise, right half must be sorted
        else {
            if (target >= v[mid] && target <= v[high])
                low = mid + 1;  // Target lies in right half
            else
                high = mid - 1; // Target lies in left half
        }
    }

    return -1; // Target not found
}

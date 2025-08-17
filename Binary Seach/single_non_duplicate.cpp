// LeetCode Problem: Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int low = 1, high = n - 2;

        // ✅ Edge cases
        if (n == 1) 
            return v[0];
        if (v[0] != v[1]) 
            return v[0];
        if (v[n - 1] != v[n - 2]) 
            return v[n - 1];

        // ✅ Binary Search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // ✅ Found the single element
            if (v[mid] != v[mid - 1] && v[mid] != v[mid + 1])
                return v[mid];

            // ✅ Decide which half to search
            if ((v[mid] == v[mid - 1] && mid % 2 != 0) || 
                (v[mid] == v[mid + 1] && mid % 2 == 0)) {
                low = mid + 1;   // Single element lies on right side
            } else {
                high = mid - 1;  // Single element lies on left side
            }
        }

        return -1; // Should never reach here if input is valid
    }
};

/*
🔎 Dry Run Example:
Input: v = [1, 1, 2, 3, 3, 4, 4, 8, 8]

Step 1: n=9 → low=1, high=7
   → Edge cases fail (since first=1, last=8 are paired)

Step 2: mid = (1+7)/2 = 4 → v[mid] = 3
   → v[mid] == v[mid-1] (3 == 3) and mid=4 (even index)
   → Condition fails → single element lies on left
   → high = mid - 1 = 3

Step 3: low=1, high=3 → mid = 2 → v[mid] = 2
   → v[mid]!=v[mid-1] && v[mid]!=v[mid+1]
   → ✅ Found single element = 2 at index=2

Answer = 2
*/

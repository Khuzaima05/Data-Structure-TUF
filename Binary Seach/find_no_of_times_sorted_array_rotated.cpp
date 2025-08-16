// GeeksforGeeks Problem: Find the Rotation Count
// https://www.geeksforgeeks.org/problems/rotation4723/1

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& v) {
        int n = v.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX, index = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // ✅ Left half is sorted
            if (v[mid] >= v[low]) {
                if (ans >= v[low]) {
                    ans = v[low];
                    index = low; // store index of minimum element
                }
                low = mid + 1; // move to right half
            }
            // ✅ Right half is unsorted → pivot lies here
            else {
                if (ans >= v[mid]) {
                    ans = v[mid];
                    index = mid; // store index of minimum element
                }
                high = mid - 1; // move to left half
            }
        }

        return index; // ✅ Rotation count is index of minimum element
    }
};

/*
🔎 Dry Run Example:
Input: v = [4, 5, 1, 2, 3]

Step 1: low=0, high=4 → mid=2 → v[mid]=1
   → v[mid] < v[low] → right half is unsorted
   → ans=1, index=2
   → high=1

Step 2: low=0, high=1 → mid=0 → v[mid]=4
   → v[mid] >= v[low] → left half is sorted
   → ans=1 (unchanged), index=2
   → low=1

Step 3: low=1, high=1 → mid=1 → v[mid]=5
   → v[mid] >= v[low] → left half sorted
   → ans=1 (unchanged), index=2
   → low=2 (loop ends)

✅ Minimum element = 1 at index = 2
✅ Array was rotated 2 times
*/
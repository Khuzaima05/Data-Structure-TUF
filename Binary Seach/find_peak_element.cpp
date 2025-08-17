/*
🔗 LeetCode Problem: https://leetcode.com/problems/find-peak-element/

📌 Problem:
A peak element is an element that is strictly greater than its neighbors.  
Given an integer array `nums`, find a peak element, and return its index.  
If the array contains multiple peaks, return the index to any of the peaks.  

You may imagine that nums[-1] = nums[n] = -∞.

⚡ Constraints:
- 1 <= nums.length <= 1000
- -2^31 <= nums[i] <= 2^31 - 1
- nums[i] != nums[i + 1] for all valid i

---------------------------------------------------------
✅ Approach: Binary Search
- If `nums[mid]` is greater than both neighbors → Peak found.
- If left neighbor is greater → Move left.
- If right neighbor is greater → Move right.
- Always guaranteed to find a peak.

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        
        // Edge cases for first and last elements
        if (n == 1) return 0;
        if (v[0] > v[1]) return 0;
        if (v[n - 1] > v[n - 2]) return n - 1;
        
        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is a peak
            if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
                return mid;
            
            // Move towards the greater neighbor
            if (v[mid] > v[mid - 1])
                low = mid + 1;  // go right
            else
                high = mid - 1; // go left
        }
        return -1; // Should never reach here
    }
};

// ---------------------------------------------------------
// 🔍 Example Dry Run
/*
Input: nums = [1, 2, 1, 3, 5, 6, 4]

Step 1: n = 7
        First element check → 1 < 2, not peak
        Last element check  → 4 < 6, not peak

Step 2: low = 1, high = 5
        mid = (1+5)/2 = 3 → nums[3] = 3
        nums[2]=1 < 3 but nums[4]=5 > 3 → move right

Step 3: low = 4, high = 5
        mid = 4 → nums[4] = 5
        nums[3]=3 < 5 and nums[5]=6 > 5 → move right

Step 4: low = 5, high = 5
        mid = 5 → nums[5] = 6
        nums[4]=5 < 6 and nums[6]=4 < 6 → PEAK FOUND

Output: index = 5
*/

// ---------------------------------------------------------
// 🚀 Driver Code
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element is at index: " << peakIndex 
         << " (value = " << nums[peakIndex] << ")" << endl;
    return 0;
}

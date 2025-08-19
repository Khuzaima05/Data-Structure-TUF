/*
------------------------------------------------------------
📌 Problem: Koko Eating Bananas
LeetCode Link: https://leetcode.com/problems/koko-eating-bananas/

Koko loves bananas. There are n piles of bananas, the i-th pile has v[i] bananas.  
The guards have gone and will come back in h hours.  
Koko can decide her bananas-per-hour eating speed `k`.  
Each hour, she chooses a pile and eats up to `k` bananas from it.  
If the pile has fewer than `k`, she eats all bananas and that pile is finished.

Return the **minimum integer k** such that she can eat all bananas within `h` hours.

------------------------------------------------------------
⚡ Approach: Binary Search
- The eating speed `k` lies between [1, max(v)].
- Use binary search to find the smallest valid `k`.
- For each candidate `k`, calculate total hours needed:
    time = sum( ceil(v[i] / k) ) for all piles.
- If time <= h → try smaller speed (move left).
- Else → need faster speed (move right).

Time Complexity: O(n * log(max(v)))  
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    // Utility function to get maximum element in array
    int maxm(vector<int>& v) {
        int maxVal = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            maxVal = max(v[i], maxVal);
        }
        return maxVal;
    }

    // Function to compute time required if eating speed is k
    long long time_taken(vector<int>& v, int k) {
        long long time = 0;
        for (int i = 0; i < v.size(); i++) {
            // Use ceil(v[i]/k) → convert to integer safely
            time += (v[i] + k - 1) / k; // avoids floating point
        }
        return time;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
        int high = maxm(v);   // max pile size is the upper bound
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (time_taken(v, mid) <= h) {
                ans = mid;        // valid speed, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;    // too slow, need faster speed
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------
📝 Dry Run Example:
Input: v = [3,6,7,11], h = 8

maxm(v) = 11 → search space [1, 11]

Iteration 1: mid = 6
time = ceil(3/6)+ceil(6/6)+ceil(7/6)+ceil(11/6)
     = 1+1+2+2 = 6 ≤ 8 → valid → ans=6, high=5

Iteration 2: mid = 3
time = ceil(3/3)+ceil(6/3)+ceil(7/3)+ceil(11/3)
     = 1+2+3+4 = 10 > 8 → too slow → low=4

Iteration 3: mid = 4
time = ceil(3/4)+ceil(6/4)+ceil(7/4)+ceil(11/4)
     = 1+2+2+3 = 8 ≤ 8 → valid → ans=4, high=3

Loop ends. Final ans = 4
------------------------------------------------------------
*/

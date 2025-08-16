#include <vector>
using namespace std;

// ===================================================
// Concept: Lower Bound & Upper Bound
// ---------------------------------------------------
// Lower Bound:
// - First index where value ≥ target (target itself or next bigger)
// - Returns index of first occurrence of target
//
// Upper Bound:
// - First index where value > target (strictly greater)
// - Returns index of last occurrence of target
// ===================================================

// 1. Find First and Last Position of Element in Sorted Array (https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

// ===============================
// Lower Bound Function
// ===============================
int lower_bound(vector<int>& v, int x) {
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x <= v[mid]) {
            high = mid - 1;
            if (x == v[mid])
                ans = mid;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// ===============================
// Upper Bound Function
// ===============================
int upper_bound(vector<int>& v, int x) {
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else {
            if (v[mid] == x)
                ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}

// ===================================================
// Find First and Last Position of Element in Sorted Array
// ===================================================
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(lower_bound(nums, target));
    ans.push_back(upper_bound(nums, target));
    return ans;
}

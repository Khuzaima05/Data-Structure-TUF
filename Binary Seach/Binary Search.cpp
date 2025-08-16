// LeetCode Problems:
// 1. Binary Search (https://leetcode.com/problems/binary-search/)

#include <vector>
using namespace std;

// ===============================
// Recursive Binary Search
// ===============================
int binary_recursive(vector<int>& v, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (v[mid] == target)
        return mid;
    else if (v[mid] > target)
        return binary_recursive(v, low, mid - 1, target);
    else
        return binary_recursive(v, mid + 1, high, target);
}

// ===============================
// Iterative Binary Search
// ===============================
int binary_iterative(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
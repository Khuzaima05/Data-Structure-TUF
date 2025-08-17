# 🔍 Binary Search and Variants

Binary Search is one of the most fundamental algorithms in computer science.  
It is used to efficiently find an element in a **sorted array** in **O(log n)** time.

This repository contains implementations of:

- Recursive Binary Search
- Iterative Binary Search
- Lower Bound (first index where value ≥ target)
- Upper Bound (first index where value > target)
- Search in Rotated Sorted Array (no duplicates)
- Search in Rotated Sorted Array II (with duplicates)
- Find Minimum in Rotated Sorted Array
- Find Rotation Count in Rotated Sorted Array
- Single Element in a Sorted Array

---

## 📖 What is Binary Search?

Binary Search works on **sorted arrays**.  
Instead of scanning every element (like Linear Search), it:

1. Picks the **middle element**.
2. If the middle is the target → return it.
3. If the target is smaller → search in the **left half**.
4. If the target is larger → search in the **right half**.
5. Repeat until found or search space is empty.

---

## 📌 Visualization

Suppose we have the sorted array:

```
Index:  0   1   2   3   4   5   6
Array: [1,  2,  4,  4,  4,  5,  7]
```

Target = `4`

### Step-by-step search:

```
low = 0, high = 6
mid = 3 → arr[mid] = 4 ✅ Found at index 3
```

---

## 📌 Lower Bound & Upper Bound

### ✅ Lower Bound

- First index where value is **greater than or equal to** target.
- Example: For target = `4`
  ```
  Array: [1, 2, 4, 4, 4, 5, 7]
  Lower Bound = index 2  (first 4)
  ```

### ✅ Upper Bound

- First index where value is **strictly greater than** target.
- Example: For target = `4`
  ```
  Array: [1, 2, 4, 4, 4, 5, 7]
  Upper Bound = index 4  (last 4)
  ```

👉 Using both, we can find the **first and last occurrence** of a target.

---

## 📌 Search in Rotated Sorted Array (No Duplicates)

When a sorted array is rotated (e.g., `[4,5,6,7,0,1,2]`), binary search still works!

Steps:

1. One half of the array (left or right) is always sorted.
2. Check if target lies in the sorted half.
3. Continue search in that half.

Example:

```
Array:  [4, 5, 6, 7, 0, 1, 2]
Target: 0

Step 1: mid=3 → arr[mid]=7
Left half [4,5,6,7] is sorted, but 0 not in it → search right half.

Step 2: mid=5 → arr[mid]=1
Still not match → search left half of this region.

Step 3: mid=4 → arr[mid]=0 ✅ Found at index 4
```

⏱ Complexity: **O(log n)**

---

## 📌 Search in Rotated Sorted Array II (With Duplicates)

This is a variation where the rotated array **may contain duplicates** (e.g., `[2,5,6,0,0,1,2]`).

The challenge:

- If `arr[low] == arr[mid] == arr[high]`, we **cannot decide which side is sorted**.
- In that case, shrink the search space by moving `low++` and `high--`.

Example:

```
Array:  [2, 5, 6, 0, 0, 1, 2]
Target: 0

Step 1: mid=3 → arr[mid]=0 ✅ Found
```

⏱ Complexity:

- **Worst Case**: O(n) (when duplicates force shrinking one by one)
- **Best/Average Case**: O(log n)

---

## 📌 Find Minimum in Rotated Sorted Array (Without Duplicates)

**Problem:**  
We are given a rotated sorted array **without duplicates** (e.g., `[4, 5, 6, 7, 0, 1, 2]`).  
The task is to find the **minimum element**.

---

### ⚡ Approach

- If `arr[mid] > arr[high]` → Minimum lies in the **right half** → `low = mid + 1`.
- Else → Minimum lies in the **left half (including mid)** → `high = mid`.

Example:

```
Array:  [4, 5, 6, 7, 0, 1, 2]
Minimum element = 0

Step 1: mid=3 → arr[mid]=7, arr[high]=2 → arr[mid] > arr[high] → move low=mid+1 → low=4
Step 2: low=4 → arr[low]=0 ✅ Found minimum


Minimum element = 0

```

---

### ⏱ Complexity

- **Time:** O(log n)
- **Space:** O(1)

---

## 📌 Single Element in a Sorted Array

**Problem:**  
You are given a **sorted array** where every element appears **twice**, except one element which appears **only once**.  
Find that single element.

```
Example:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

---

### ⚡ Approach

- Use **binary search** to find the unique element.
- Key observation:
  - If `mid` is even → its duplicate should be at `mid+1`.
  - If `mid` is odd → its duplicate should be at `mid-1`.
- Otherwise, the unique element lies in the **other half**.


---

### 🔎 Dry Run

Array: [1, 1, 2, 3, 3, 4, 4, 8, 8]

Step 1: low=1, high=7 → mid=4 → arr[mid]=3
arr[mid]==arr[mid-1] and mid is even → Wrong pairing → search left half
high=3

Step 2: low=1, high=3 → mid=2 → arr[mid]=2
arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1] → ✅ Found single element

Answer = 2

```

---

### ⏱ Complexity

- **Time:** O(log n)
- **Space:** O(1)

---

## 📌 Find Peak Element

**Problem:**  
A **peak element** is an element that is strictly greater than its neighbors.  
Given an integer array `nums`, find a peak element and return its index.  
If the array contains multiple peaks, return the index to **any one of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`.

```

Example:
Input: [1,2,1,3,5,6,4]
Output: 5 // nums[5] = 6 is a peak


### ⚡ Approach

- Handle base cases:
  - If array size = 1 → return index `0`.
  - If first element > second → return index `0`.
  - If last element > second last → return `n-1`.
- Otherwise use **binary search** between `1` and `n-2`:
  - If `nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]` → return `mid`.
  - If slope is **increasing** (`nums[mid] > nums[mid-1]`) → move right.
  - Else → move left.

---

### 🔎 Dry Run

Array: [1, 2, 1, 3, 5, 6, 4]

Step 1: low=1, high=5 → mid=3 → nums[3]=3
Neighbors: nums[2]=1, nums[4]=5 → not a peak, slope increasing → move right

Step 2: low=4, high=5 → mid=4 → nums[4]=5
Neighbors: nums[3]=3, nums[5]=6 → not a peak, slope increasing → move right

Step 3: low=5, high=5 → mid=5 → nums[5]=6
Neighbors: nums[4]=5, nums[6]=4 → ✅ peak found

Answer = 5

```

---

### ⏱ Complexity

- **Time:** O(log n)
- **Space:** O(1)

---

## 📌 Time & Space Complexity

| Algorithm                            | Time Complexity | Space Complexity |
| ------------------------------------ | --------------- | ---------------- |
| Binary Search (Iterative/Recursive)  | O(log n)        | O(1) / O(log n)  |
| Lower Bound / Upper Bound            | O(log n)        | O(1)             |
| Search in Rotated Sorted Array       | O(log n)        | O(1)             |
| Search in Rotated Sorted Array II    | O(log n) ~ O(n) | O(1)             |
| Find Minimum in Rotated Sorted Array | O(log n)        | O(1)             |
| Find Rotation Count                  | O(log n)        | O(1)             |
| Single Element in Sorted Array       | O(log n)        | O(1)             |
| Find Peak Element                    | O(log n)        | O(1)             |

---

## 📌 Example Usage

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function declarations (implementations are in .cpp files)
int binary_iterative(vector<int>& nums, int target);
int lower_bound(vector<int>& v, int x);
int upper_bound(vector<int>& v, int x);
int search(vector<int>& v, int target);         // Rotated (no duplicates)
class Solution; // For Rotated II (with duplicates)

int main() {
    vector<int> nums = {1, 2, 4, 4, 4, 5, 7};
    int target = 4;

    cout << "Binary Search (Iterative): " << binary_iterative(nums, target) << endl;
    cout << "Lower Bound: " << lower_bound(nums, target) << endl;
    cout << "Upper Bound: " << upper_bound(nums, target) << endl;

    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    cout << "Search in Rotated Array (target=0): " << search(rotated, 0) << endl;

    vector<int> rotatedDup = {2, 5, 6, 0, 0, 1, 2};
    Solution s;
    cout << "Search in Rotated Array II (target=0): " << s.search(rotatedDup, 0) << endl;

    return 0;
}
```

---

## 📌 References

- [Binary Search - LeetCode](https://leetcode.com/problems/binary-search/)
- [Find First and Last Position - LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- [Search in Rotated Sorted Array - LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [Search in Rotated Sorted Array II - LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
- [Find Minimum in Rotated Sorted Array - LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)
- [Find Rotation Count - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/find-rotation-count-rotated-sorted-array/)
- [Single Element in a Sorted Array - LeetCode](https://leetcode.com/problems/single-element-in-a-sorted-array/)

---

✨ With binary search, you don’t check all elements → you **divide and conquer** until the target is found (or not found).

```
Every step halves the search space ➝ O(log n) time (except worst case with duplicates).
```

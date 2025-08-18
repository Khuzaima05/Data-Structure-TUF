/*
------------------------------------------------------------
📌 Problem: Find Nth Root of M
LeetCode/GFG Variant: "Nth Root of M"

Given two numbers n and m, find the integer nth root of m.  
Return the integer x such that:
    x^n = m
If no such integer exists, return -1.

------------------------------------------------------------
⚡ Approach: Binary Search
- The nth root of m lies between 1 and m.
- Use binary search:
  - Compute mid^n using helper function (with early stop).
  - If mid^n == m → return mid.
  - If mid^n > m  → search left.
  - If mid^n < m  → search right.
- If no exact root exists → return -1.

Time Complexity: O(n * log m)  
Space Complexity: O(1)
------------------------------------------------------------
*/

// Helper function: computes x^n but stops if product > m
long long multiple(int x, int n, int m) 
{
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * x;
        if (ans > m) return ans;  // early exit to avoid overflow
    }
    return ans;
}

int nthRoot(int n, int m) 
{
    int low = 1;      
    int high = m;     

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        long long val = multiple(mid, n, m);

        if (val == m) {
            return mid;     // found exact nth root
        }
        else if (val > m) {
            high = mid - 1; // go left
        }
        else {
            low = mid + 1;  // go right
        }
    }

    return -1;  // no integer nth root exists
}

/*
------------------------------------------------------------
📝 Dry Run Example: n=5, m=243

Initial: low=1, high=243

Iteration 1:
mid = (1+243)/2 = 122
multiple(122, 5, 243) → exceeds 243 early → val > m → high=121

Iteration 2:
mid = (1+121)/2 = 61
multiple(61, 5, 243) → exceeds 243 early → high=60

Iteration 3:
mid = (1+60)/2 = 30
multiple(30, 5, 243) → exceeds 243 early → high=29

...
Iteration 6:
mid = (3+4)/2 = 3
3^5 = 243 → ✅ found → return 3

------------------------------------------------------------
*/

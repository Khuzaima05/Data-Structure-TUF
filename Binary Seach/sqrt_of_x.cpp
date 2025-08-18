/*
------------------------------------------------------------
📌 Problem: Sqrt(x)
LeetCode Link: https://leetcode.com/problems/sqrtx/

Given a non-negative integer x, return the floor value 
of its square root (i.e., the largest integer r such that r*r ≤ x).
You cannot use built-in sqrt() function.
------------------------------------------------------------

⚡ Approach: Binary Search
- The square root of x lies between 0 and x.
- Use binary search in this range.
- If mid*mid ≤ x → store mid as a candidate and move right.
- Else → move left.
- Return the last valid candidate (ans).

Time Complexity: O(log x)
Space Complexity: O(1)
------------------------------------------------------------
*/

int mySqrt(int x) 
{
    long long low = 0;          // search range start
    long long high = x;         // search range end
    long long ans = 0;          // stores latest valid answer

    while (low <= high) 
    {
        // Safer than (low + high)/2 to avoid overflow
        long long mid = low + (high - low) / 2;

        if (mid * mid <= x) {
            // mid is a possible answer, store it
            ans = mid;

            // try to find a larger valid sqrt candidate
            low = mid + 1;
        } 
        else {
            // mid*mid exceeded x, move left
            high = mid - 1;
        }
    }

    // Return final answer as int
    return (int)ans;
}

/*
------------------------------------------------------------
📝 Dry Run Example 1: x = 10

Initial: low=0, high=10, ans=0

Iteration 1:
mid = (0+10)/2 = 5
5*5 = 25 > 10 → too large → high=4

Iteration 2:
mid = (0+4)/2 = 2
2*2 = 4 ≤ 10 → valid → ans=2, low=3

Iteration 3:
mid = (3+4)/2 = 3
3*3 = 9 ≤ 10 → valid → ans=3, low=4

Iteration 4:
mid = (4+4)/2 = 4
4*4 = 16 > 10 → too large → high=3

Now low=4, high=3 → loop ends.

✅ Final Answer: ans = 3
(since sqrt(10) ≈ 3.16, floor = 3)
------------------------------------------------------------

📝 Dry Run Example 2: x = 16

Initial: low=0, high=16, ans=0

Iteration 1:
mid = (0+16)/2 = 8
8*8 = 64 > 16 → too large → high=7

Iteration 2:
mid = (0+7)/2 = 3
3*3 = 9 ≤ 16 → valid → ans=3, low=4

Iteration 3:
mid = (4+7)/2 = 5
5*5 = 25 > 16 → too large → high=4

Iteration 4:
mid = (4+4)/2 = 4
4*4 = 16 ≤ 16 → valid → ans=4, low=5

Now low=5, high=4 → loop ends.

✅ Final Answer: ans = 4
(since sqrt(16) = 4 exactly)
------------------------------------------------------------
*/

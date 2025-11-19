# Climbing Stairs — Dynamic Programming Explanation

The problem states:

> You are climbing a staircase. It takes **n** steps to reach the top.  
> Each time you can either climb **1** or **2** steps.  
> In how many distinct ways can you climb to the top?

---

## Examples

### Example 1
**Input:** `n = 2`  
**Output:** `2`

Explanation:
1. 1 step + 1 step  
2. 2 steps  

---

### Example 2
**Input:** `n = 3`  
**Output:** `3`

Explanation:
1. 1 step + 1 step + 1 step  
2. 1 step + 2 steps  
3. 2 steps + 1 step  

---

# Brute Force Approach

The brute force method uses simple recursion.

For every `n`, you can reach it either from:

- `n - 1` (taking 1 step)
- `n - 2` (taking 2 steps)

ways(n) = ways(n - 1) + ways(n - 2)

This forms the Fibonacci-like pattern.

### ❌ Problem with Brute Force
The recursive calls repeat the same subproblems again and again.  
This creates an **exponential time complexity**:

Time Complexity: O(2^n)

This becomes extremely slow for larger `n`.

---

# Optimized Approach — Dynamic Programming (Memoization)

To avoid recalculating the same values, we store already computed results in a `dp` array.

### Steps:

1. Create an array `dp[]` of size `n + 1`. Though here we took it as dp[100]. It is recommended to write dp[n+1].
2. Initialize all values to `-1` (meaning "not computed yet").
3. Use recursion, but whenever a value is computed, store it in `dp[n]`.
4. If the value is already stored, return it directly.

This reduces the time complexity drastically.

### ✔ Time Complexity (DP): O(n)

### ✔ Space Complexity (DP): O(n) [recursion + dp array]


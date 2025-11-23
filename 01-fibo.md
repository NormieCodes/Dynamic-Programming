# Fibonacci Number — Dynamic Programming Explanation

The Fibonacci sequence is defined as:

- F(0) = 0  
- F(1) = 1  
- F(n) = F(n - 1) + F(n - 2) for n > 1  

The task is: **Given n, compute F(n)**.

---

## Understanding the Problem

Each Fibonacci number depends on the previous two numbers.  
For example:

- F(2) = F(1) + F(0) = 1  
- F(3) = F(2) + F(1) = 2  
- F(4) = F(3) + F(2) = 3  

This continues for any n.

---

# Brute Force Recursion (Not Efficient)

A simple recursive approach directly applies the definition:

F(n) = F(n−1) + F(n−2)


But this is very inefficient because:

- The same values are recomputed many times  
- The recursion tree grows exponentially  

### ❌ Time Complexity: `O(2^n)`  
This becomes extremely slow for even moderate values of `n`.

---

# Optimized Approach 1 — Memoization (Top–Down DP)

Memoization improves the brute force recursion by storing results.

### Key Idea:
- Use an array `dp`
- Initialize all values with a marker (like `-1`)
- Whenever a Fibonacci value is computed, store it in `dp[n]`
- If the same value is needed again, return it directly from the array instead of recomputing

### Benefits:
- Eliminates repeated computations  
- Reduces time complexity from exponential to linear  

### Time Complexity: `O(n)`  
### Space Complexity: `O(n)` (dp array + recursion stack)

Memoization is called the **Top–Down** approach because:
- Your logic starts from `n`  
- It breaks the problem down recursively  
- It fills the dp array *after* recursive calls complete  

---

# Optimized Approach 2 — Tabulation (Bottom–Up DP)

Tabulation takes the opposite approach.

### Key Idea:
- Start from the smallest base values (F(0), F(1))
- Build the dp array step-by-step up to F(n)
- No recursion, only iteration

So you compute:

dp[2] = dp[1] + dp[0]
dp[3] = dp[2] + dp[1]
dp[4] = dp[3] + dp[2]
...
dp[n]

### Benefits:
- No recursion stack  
- Very fast and memory efficient  

### Time Complexity: `O(n)`  
### Space Complexity: `O(n)`

This is called the **Bottom–Up** approach because:
- You compute smaller results first  
- Use them to build the final answer  

---

# Memoization vs Tabulation

| Aspect | Memoization | Tabulation |
|-------|-------------|------------|
| Approach | Top–Down | Bottom–Up |
| Uses Recursion? | Yes | No |
| dp Array Filled | As needed | Sequentially |
| Time Complexity | O(n) | O(n) |
| Space Complexity | O(n) | O(n), can be reduced to O(1) |

---

# Final Understanding

The Fibonacci problem is a perfect introduction to Dynamic Programming because:

- It shows how repeated work can be avoided  
- It demonstrates both major DP techniques: memoization and tabulation  
- Both methods drastically improve performance from exponential to linear time  

By storing previous results, we turn a slow recursive problem into an efficient DP solution.

---

#include<stdio.h>

int countWays(int n, int* dp) {
  if (n <= 1) return 1;

  if (dp[n] != -1) return dp[n];

  int left = countWays(n-1, dp);
  int right = countWays(n-2, dp);

  return dp[n] = left + right;
}

int climbStairs(int n) {
  int dp[100];

  for(int i = 0; i <= n; i++) 
    dp[i] = -1;

  return countWays(n, dp);
}

int main () {
  int n = 45;
  
  printf("The number of ways to climb the stairs of %d are %d\n", n, climbStairs(n));
}

//Time Complexity using memoization is: O(n)
//Space Complexity using memoization is: O(n)

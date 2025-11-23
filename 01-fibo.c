#include<stdio.h>
#include<stdlib.h>

int m_fibo(int n, int* dp){  //Memoization Method : TOP DOWN APPROACH
  if (n <= 1) return n;

  if (dp[n] != -1) return dp[n];

  return dp[n] = m_fibo(n-1, dp) + m_fibo(n-2, dp); 
}

int t_fibo(int n, int* dp){  //Tabulation Method : BOTTOM UP APPROACH

  for (int i = 2; i < n+1; i++) {
    dp[i] = dp[i-1] + dp[i-2]; 
  }
  return dp[n];
}

int main() {

  int n = 6;
  int *m_dp = (int*)malloc(sizeof(int)*(n+1));

  m_dp[0] = 0; m_dp[1] = 1; 

  for(int i = 2; i < n+1; i++) m_dp[i] = -1;
  
  printf("%d \n",m_fibo(n, m_dp));
  
  for(int i = 0; i < n+1; i++) printf("%d ", m_dp[i]); 
  printf("\n");
  free(m_dp);
  
  /* Time Complexity : O(n) and Space Complexity : O(n) [recursion stack space] + O(n) [Array]*/
  /* Recursion stack space = maximum depth of active recursive calls
  The longest path of recursive calls that are active at the same time
  In this case its O(n) as fibo(6)->fibo(5)->fibo(4)->fibo(3)->fibo(2)->fibo(1)->fibo(0)*/

  int *t_dp = (int*)malloc(sizeof(int)*(n+1));
   t_dp[0] = 0; t_dp[1] = 1; 

  for(int i = 2; i < n+1; i++) t_dp[i] = -1;

  printf("%d \n",t_fibo(n, t_dp));
  
  for(int i = 0; i < n+1; i++) printf("%d ", t_dp[i]); 
  free(t_dp);

}

  /* Time Complexity : O(n) and Space Complexity : O(n) [Array]*/
  /* No Recursion Stack space is used here.
  In this case its O(n) as dp[0]->dp[1]->dp[2]->dp[3]->dp[4]->dp[5]->dp[6]*/
#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000   // safe large value

/*Matrix Chain Multiplication is a dynamic programming optimization problem that determines the most efficient way to multiply a sequence of matrices.

Since matrix multiplication is associative, we can parenthesize the product in multiple ways but different parenthesizations can lead to different numbers of scalar multiplications.

The goal of MCM is:

To find the order of multiplying the matrices that results in the minimum number of scalar multiplications.*/


//First fill the diagonals as 0 and the rest as INF
void fill(int n, int A[n][n]) {
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) A[i][j] = 0;
      else A[i][j] = INF;
    }
  }
}


/*This is the function that computes for M and S matrices respectively. 
Here diff is the difference between i and j. That is length of the chain - 1. 
This usually means that when diff = 0, its a single matrix so cost is 0. 
diff = 1 then its a chain of length 2
diff = 2 then its a chain of length 3 and so on...

i is the starting index of the chain
j is the ending index of the chain

i is set as n - diff because when diff is 1 we have these pairs of matrices
A0A1, A1A2, A2A3
notice that the value of i starts from 0 to 2
now compute n - diff -> 4 - 1 -> 3
i ranges from [0, 3) which is how it went in the series. i ranges from 0 to 2. 

lets Take another example, for diff = 2
A0A2, A1A3 are the existing pairs
i ranging from 0 to 1
now compute n - diff -> 4 - 2 -> 2
i ranges from [0, 2) which is how it went in the series. i ranges from 0 to 1. 

Now lets check for j 
when diff was 1, j ranged from 1 to 3. 
when diff was 2, j ranged from 2 to 3. 
This means that j = i + diff.
As when diff was 1, 
diff + i => 1 + 2 -> 3 -> j
when diff was 2, 
diff + i => 2 + 1 -> 3 -> j

So this is how we computed for the starting index of the chain and the ending index of the chain. This computation completely ignores the area below the diagonal line (lower triangular part). 
*/
void mcm(int n, int p[], int M[n][n], int S[n][n]) {
  for (int diff = 1; diff < n; diff++) {                  
    for (int i = 0; i < n - diff; i++) {                  

      int j = i + diff; 
      M[i][j] = INF; // Reset M[i][j] for every computation
      
      // i<= k < j is the usual range
      for (int k = i; k < j; k++) {  
        int cost = M[i][k] + M[k+1][j] + (p[i] * p[k+1] * p[j+1]); // we compute the cost here. 
      

      if (cost < M[i][j]) {  
          M[i][j] = cost; // if the cost is minimum store it, else dont. 
          S[i][j] = k; // then update the S table. This the value of k at which splitting is optimal
        }
      }
    }
  }
}

//Print matrix function
void printMatrix(int n, int A[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == INF) printf("INF ");
      else printf("%3d ", A[i][j]);
    }printf("\n");
  }printf("\n");
}


/*when we are multiplying i and j matrices, k is said to be the best split point. Such that the cost of multiplications is minimum. Lets understand how we are parenthesizing here
when k is used to split i and j it is represented as 
i .... k, k+1 .... j
k = S[i][j]
we use recursion to put parenthesis here. This recursive function is uses top down approach 
we continue to split until there is a single matrix like 
A[0][0], A[1][1], A[2][2], ....
If this is the case then i == j, so print A, do nothing else 

if not then open the parentheses, let the value of k do the splitting, close parentheses. 

Lets get deeper with the explanation
left partition : printOrder(i, S[i][j]) 
right partition : printOrder(S[i][j], j)

First the function will print '(' then it will expand the left partition, every time it expands the left paritition, it is printing '('. Now when left partition reaches the base case, it will return A (base condtion).
Now it will move to right parition, expand it to the fullest, and when it reaches the base case, it will print A then print ')'. It recursively prints ')' till we are back to the first function call.

*/
void printOrder(int i, int j, int n, int S[n][n]) {
  if (i == j) {
    printf("A%d", i+1);
    return;
  }

  printf("(");
  printOrder(i, S[i][j], n, S);
  printOrder(S[i][j] + 1, j, n, S);
  printf(")");

}

int main () {
  int n = 4; // Four matrix multiplication
  int p[] = {10, 20, 30, 40, 50}; // Dimensions stored (n+1)

  int M[n][n]; int S[n][n];  // M matrix is to store the cost of multiplcation whereas S matrix stores the value of k at which the split it optimal
 
  fill(n, M); 
  fill(n, S);
  

  mcm(n, p, M, S);

  printf("All Minimum multiplication costs are: \n");
  printMatrix(n, M);

  printf("All Optimal split positions are: \n");
  printMatrix(n, S);

  printf("The minimum cost is : %d\n", M[0][n-1]);

  printf("The Optimal Parenthesization of these matrixes is: \n");

  printOrder(0, n-1, n, S);
  printf("\n");
}


//Time Complexity : O(n^3)
//Space Complexity : O(n^2)
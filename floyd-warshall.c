#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000   // safe large value


/*Floyd-Warshall is a dynamic programming tabulation algorithm used to find shortest distances between all node pairs, and it can also detect negative cycles. The final matrix itself contains the shortest path results.*/

/*Mathematically, when we talk about graph, the nodes usually start from 1 to n. But as we know that programming languages use 0 indexing, I find it better to start with 0 itself. Here's why:
1 based indexing 
programming languages would still need 0th index. If we ignore the 0th row and 0th column, then we are wasting some space here. Leave it untreated and these spots will contain garbage values. This is not a good practice. 
instead i would prefer using 0th based indexing.

0th based indexing
if we use 0th based indexing, the size of the matrix will be NxN instead of (N+1)x(N+1) (as 1 based indexing includes 0, 1, ....n)
Nodes will be numbered 0 to n-1
No wasted row/cloumn
*/

/*To Keep it simple, we can start the nodes from 0 to n-1. 
The approach that i am going to follow here is simple, we are given with the number of edges and an edge set. We have to create an adjacency matrix first (D0). Then we'll apply Floyd Warshall algorithm. This will give us a proper clarity.
*/


int min (int a, int b){
  return (a < b)? a : b;
}

void floyd_Warshall(int n, int D[n][n]) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        D[i][j] = min(D[i][j], D[i][k]+ D[k][j]);
      }
    }
  }
}

int main (){
  int n = 4;
  int edges[][3] = {
    {0, 1, 3}, {0, 3, 7}, {1, 0, 8},
    {1, 2, 2}, {2, 0, 5}, {2, 3, 1}, 
    {3, 0, 2}
  };

  int edgeCount = sizeof(edges)/sizeof(edges[0]);

  int D[n][n];


  for (int j = 0; j < n; j++) {
  //Intialize D with INF and 0 on diagonals

  for (int i = 0; i < n; i++) {
      if (i == j) 
        D[i][j] = 0;

      else 
        D[i][j] = INF;
    }
  }

  //Now files edges into D. We know that edges = {{0, 1, 3}} means that the weight between Node 0 and Node 1 is 3.

  for (int i = 0; i < edgeCount; i++) {
    int u = edges[i][0];   // Node U
    int v = edges[i][1];   // Node V 
    int w = edges[i][2];   // Weight between Node U and Node V 

    D[u][v] = w;
  }

  //print D0 Matrix
  printf("D0 Matrix: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (D[i][j] == INF) printf("INF ");
      else printf("%3d ", D[i][j]);
    }
    printf("\n");
  }


  // Now lets Apply Floyd Warshall Algorithm 

  floyd_Warshall(n, D);


  //print the final all pairs shortest path 
  printf("All Pairs Shortest Path\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", D[i][j]);
    }
    printf("\n");
  }
}
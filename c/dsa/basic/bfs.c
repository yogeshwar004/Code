/*11. Develop a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using
DFS/BFS method
*/
#include <stdio.h>
int a[10][10], n, visited[10];
void dfs(int s) {
  int i;
  visited[s] = 1;
  printf("%d\t", s);
  for (i = 0; i < n; i++) {
    if (a[s][i] == 1 && visited[i] == 0)
      dfs(i);
  }
}
void bfs(int s) {
  int i, f = 0, r = -1, q[n];
  visited[s] = 1;
  while (1) {
    printf("%d->", s);
    for (i = 0; i < n; i++) {
      if (a[s][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        q[++r] = i;
      }
    }
    if (f > r)
      return;
    s = q[f++];
  }
}
int main() {
  int i, j, s;
  printf("Enter the number of nodes :\n");
  scanf("%d", &n);
  printf("Enter the graph in adjacency matrix format :\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  }
  for (i = 0; i < n; i++)
    visited[i] = 0;
  printf("Enter the starting nodes :\n");
  scanf("%d", &s);
  printf("DFS TRAVERSAL : \n");
  dfs(s);
  for (i = 0; i < n; i++)
    visited[i] = 0;
  printf("\nBFS TRAVERSAL : \n");
  bfs(s);
}

/*
output:
Enter the number of nodes :
5
Enter the graph in adjacency matrix format :
0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 0
0 0 1 0 0
Enter the starting nodes :
1
DFS TRAVERSAL :
1->0->2->3->4->
BFS TRAVERSAL :
1->0->2->3->4->

*/
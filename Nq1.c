#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int a[MAX], n, top = -1;
int count = 0; // to keep track of the number of solutions found

bool isSafe(int row, int column) {
  int i;
  for (i = 0; i < row; i++)
    if (a[i] == column || abs(a[i] - column) == abs(i - row))
      return false;
  return true;
}

void printSolution(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i] == j)
        printf("Q ");
      else
        printf("_ ");
    }
    printf("\n");
  }
  printf("\n");
}

bool solveNQUtil(int row, int n) {
  if (row == n) {
    printSolution(n);
    count++;
    return false; // backtrack
  }
  int column;
  for (column = 0; column < n; column++) {
    if (isSafe(row, column)) {
      a[++top] = column;
      if (solveNQUtil(row + 1, n))
        return true;
      top--;
    }
  }
  return false;
}

void solveNQ(int n) {
  if (!solveNQUtil(0, n)) {
    //printf("Solution does not exist");
    return;
  }
}

int main() {
  printf("Enter the number of queens: ");
  scanf("%d", &n);
  solveNQ(n);
  printf("\nTotal solutions found: %d\n", count);
  return 0;
}

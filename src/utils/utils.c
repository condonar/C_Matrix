#include "utils.h"

void ExtractSubmatrix(int row, int col, matrix_t *A, matrix_t *submatrix) {
  int r = 0;
  int c = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != col) {
          submatrix->matrix[r][c] = A->matrix[i][j];
          c++;
        }
      }
      c = 0;
      r++;
    }
  }
}
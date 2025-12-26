#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OPERATION_OK;

  int rows = A->columns, cols = A->rows;
  status = s21_create_matrix(rows, cols, result);
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return status;
}
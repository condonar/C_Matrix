#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OPERATION_OK;

  if (A->columns != B->rows) {
    status = CALCULATION_ERROR;
  } else {
    status = s21_create_matrix(A->rows, B->columns, result);
    int k = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = A->matrix[i][k] * B->matrix[k][j];
      }
    }
    while (++k < A->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}
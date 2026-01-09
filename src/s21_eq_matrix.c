#include "s21_matrix.h"

static double Module(double number);

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if (A->rows != B->rows || A->columns != B->columns) {
    status = FAILURE;
  } else {
    for (int i = 0; i < A->rows && status != FAILURE; i++) {
      for (int j = 0; j < A->columns && status != FAILURE; j++) {
        if (Module(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) status = FAILURE;
      }
    }
  }

  return status;
}

static double Module(double number) { return number > 0 ? number : -number; }
#include "s21_matrix.h"
#include "utils/utils.h"

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
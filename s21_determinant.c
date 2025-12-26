#include "s21_matrix.h"
#include "utils/utils.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OPERATION_OK;

  if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    if (A->rows == 1)
      *result = 1.0;
    else if (A->rows == 2)
      Determinant(A, result);
    else {
      *result = 0;
      int n = A->rows - 1;
      matrix_t submatrix;
      double minor = 0;

      s21_create_matrix(n, n, &submatrix);
      for (int i = 0, j = 0; j < A->columns; j++) {
        ExtractSubmatrix(i, j, A, &submatrix);
        Determinant(&submatrix, &minor);
        *result += (j + 1) * minor * ((i + j) % 2 == 0 ? 1 : -1);
      }
      s21_remove_matrix(&submatrix);
    }
  }

  return status;
}
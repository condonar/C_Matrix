#include "s21_matrix.h"
#include "utils/utils.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OPERATION_OK;

  if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else {
      *result = 0;
      int n = A->rows - 1;
      double minor = 0;
      matrix_t submatrix;
      for (int i = 0, j = 0; j < A->columns && status == OPERATION_OK; j++) {
        int status_submatrix = s21_create_matrix(n, n, &submatrix);
        if (status_submatrix == OPERATION_OK) {
          ExtractSubmatrix(i, j, A, &submatrix);
          status = s21_determinant(&submatrix, &minor);
          *result += (j % 2 == 0 ? 1 : -1) * A->matrix[i][j] * minor;
        } else {
          status = CALCULATION_ERROR;
        }
        s21_remove_matrix(&submatrix);
      }
    }
  }

  return status;
}
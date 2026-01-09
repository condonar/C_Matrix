#include "s21_matrix.h"
#include "utils/utils.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OPERATION_OK;

  if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
    double minor = 0;

    matrix_t submatrix;
    int n = A->rows - 1;

    for (int i = 0; i < A->rows && status == OPERATION_OK; i++) {
      for (int j = 0; j < A->columns && status == OPERATION_OK; j++) {
        int status_submatrix = s21_create_matrix(n, n, &submatrix);
        if (status_submatrix == OPERATION_OK) {
          ExtractSubmatrix(i, j, A, &submatrix);
          s21_determinant(&submatrix, &minor);
          result->matrix[i][j] = minor * ((i + j) % 2 == 0 ? 1 : -1);
        } else {
          status = CALCULATION_ERROR;
        }
        s21_remove_matrix(&submatrix);
      }
    }
  }

  return status;
}
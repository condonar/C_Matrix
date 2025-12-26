#include "s21_matrix.h"
#include "utils/utils.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OPERATION_OK;

  if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
    int n = A->rows - 1;
    matrix_t submatrix;
    double minor = 0;
    s21_create_matrix(n, n, &submatrix);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        ExtractSubmatrix(i, j, A, &submatrix);
        Determinant(&submatrix, &minor);
        result->matrix[i][j] = minor * ((i + j) % 2 == 0 ? 1 : -1);
      }
    }
    s21_remove_matrix(&submatrix);
  }

  return status;
}
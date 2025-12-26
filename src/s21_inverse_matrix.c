#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OPERATION_OK;

  double determinant = 0;
  s21_determinant(A, &determinant);
  if (determinant == 0.0) {
    status = CALCULATION_ERROR;
  } else {
    matrix_t tmp;
    s21_calc_complements(A, &tmp);
    s21_transpose(&tmp, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] *= -1;
      }
    }
    s21_remove_matrix(&tmp);
  }

  return status;
}
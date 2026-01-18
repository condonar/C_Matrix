#include "s21_matrix.h"
#include "utils/utils.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns) return CALCULATION_ERROR;

  int status = OPERATION_OK;
  double det = 0;
  status = s21_determinant(A, &det);

  if (status != OPERATION_OK || Module(det) < 1e-7) {
    status = CALCULATION_ERROR;
  } else {
    matrix_t complements_matrix, transposed_complements_matrix;
    status = s21_calc_complements(A, &complements_matrix);
    if (status == OPERATION_OK) {
      status = s21_transpose(&complements_matrix, &transposed_complements_matrix);
      if (status == OPERATION_OK) {
        status = s21_mult_number(&transposed_complements_matrix, 1.0 / det, result);
        s21_remove_matrix(&transposed_complements_matrix);
      }
      s21_remove_matrix(&complements_matrix);
    }
  }
  return status;
}

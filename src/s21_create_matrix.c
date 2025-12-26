#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OPERATION_OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    status = MATRIX_INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix == NULL) {
      status = MATRIX_INCORRECT;
    } else {
      double *ptr_values = (double *)malloc(rows * columns * sizeof(double));
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr_values + columns * i;
      }
    }
  }
  return status;
}
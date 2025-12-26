#include "test_helpers.h"

void FillMatrix(int rows, int columns, const double *data, matrix_t *result) {
  if (rows > 0 && columns > 0 && data && result) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = data[i * columns + j];
      }
    }
  }
}
#include <stdio.h>

#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_inverse_matrix_basic) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &expected_result);

  const double data[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  const double expected_data[] = {1.0,   -1.0, 1.0,   -38.0, 41.0,
                                  -34.0, 27.0, -29.0, 24.0};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_inverse_matrix(&A, &result);
  int expected_status = OPERATION_OK;

  int eq_status = s21_eq_matrix(&result, &expected_result);
  int expected_eq = SUCCESS;

  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(eq_status, expected_eq);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_inverse_zero_determinant) {
  matrix_t A;
  matrix_t result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_inverse_matrix(&A, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);

  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_inverse_matrix(void) {
  TCase *tcase_inverse_matrix = tcase_create("TCase inverse matrix");
  tcase_add_test(tcase_inverse_matrix, test_inverse_matrix_basic);
  tcase_add_test(tcase_inverse_matrix, test_inverse_zero_determinant);

  Suite *suite_inverse_matrix = suite_create("S21_INVERSE_MATRIX");
  suite_add_tcase(suite_inverse_matrix, tcase_inverse_matrix);

  return suite_inverse_matrix;
}
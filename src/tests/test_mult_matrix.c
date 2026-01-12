#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_mult_matrix_basic) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_result;

  int rows_a = 3, cols_a = 2;
  int rows_b = 2, cols_b = 3;
  int rows = 3, cols = 3;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);
  s21_create_matrix(rows, cols, &expected_result);

  const double data_a[] = {2.0, 4.0, 3.0, 5.0, 9.0, 7.0};
  const double data_b[] = {3.0, 5.0, 7.0, 2.0, 8.0, 6.0};
  const double expected_data[] = {14.0, 42.0, 38.0,  19.0, 55.0,
                                  51.0, 41.0, 101.0, 105.0};

  FillMatrix(rows_a, cols_a, data_a, &A);
  FillMatrix(rows_b, cols_b, data_b, &B);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_mult_matrix(&A, &B, &result);
  int expected_status = OPERATION_OK;

  int eq_status = s21_eq_matrix(&result, &expected_result);
  int expected_eq = SUCCESS;

  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(eq_status, expected_eq);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_different_rows_cols) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_result;

  int rows_a = 4, cols_a = 2;
  int rows_b = 2, cols_b = 6;
  int rows = 4, cols = 6;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);
  s21_create_matrix(rows, cols, &expected_result);

  const double data_a[] = {2.0, 4.0, 3.0, 5.0, 9.0, 7.0, 5.0, 1.0};
  const double data_b[] = {3.0, 5.0, 7.0, 4.0, 2.0, 3.0,
                           2.0, 8.0, 6.0, 9.0, 5.0, 3.0};
  const double expected_data[] = {
      14.0, 42.0,  38.0,  44.0, 24.0, 18.0, 19.0, 55.0, 51.0, 57.0, 31.0, 24.0,
      41.0, 101.0, 105.0, 99.0, 53.0, 48.0, 17.0, 33.0, 41.0, 29.0, 15.0, 18.0};

  FillMatrix(rows_a, cols_a, data_a, &A);
  FillMatrix(rows_b, cols_b, data_b, &B);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_mult_matrix(&A, &B, &result);
  int expected_status = OPERATION_OK;

  int eq_status = s21_eq_matrix(&result, &expected_result);
  int expected_eq = SUCCESS;

  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(eq_status, expected_eq);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_mult_different_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 4, cols_a = 3;
  int rows_b = 2, cols_b = 6;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data_a[] = {2.0, 4.0, 3.0, 5.0, 9.0, 7.0, 5.0, 1.0, 5.0};
  const double data_b[] = {3.0, 5.0, 7.0, 4.0, 2.0, 3.0,
                           2.0, 8.0, 6.0, 9.0, 5.0, 3.0};

  FillMatrix(rows_a, cols_a, data_a, &A);
  FillMatrix(rows_b, cols_b, data_b, &B);

  int status = s21_mult_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_mult_matrix(void) {
  TCase *tcase_mult_matrix = tcase_create("TCase mult matrix");
  tcase_add_test(tcase_mult_matrix, test_mult_matrix_basic);
  tcase_add_test(tcase_mult_matrix, test_mult_different_rows_cols);
  tcase_add_test(tcase_mult_matrix, test_mult_different_matrix);

  Suite *suite_mult_matrix = suite_create("S21_MULT_MATRIX");
  suite_add_tcase(suite_mult_matrix, tcase_mult_matrix);

  return suite_mult_matrix;
}
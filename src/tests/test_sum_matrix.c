#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_sum_matrix_basic) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &expected_result);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};
  const double expected_data[] = {2.2,  4.2,  10.8, 4.6, 8.8,
                                  15.4, 17.6, 16.2, 8.0};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(rows, cols, data, &B);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_sum_matrix(&A, &B, &result);
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

START_TEST(test_sum_matrix_different_rows) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 5, cols_a = 3;
  int rows_b = 3, cols_b = 3;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows_a, cols_a, data, &A);
  FillMatrix(rows_b, cols_b, data, &B);

  int status = s21_sum_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_different_cols) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 3, cols_a = 3;
  int rows_b = 3, cols_b = 7;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows_a, cols_a, data, &A);
  FillMatrix(rows_b, cols_b, data, &B);

  int status = s21_sum_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_not_allocate_result) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 3, cols_a = 3;
  int rows_b = 3, cols_b = 3;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows_a, cols_a, data, &A);
  FillMatrix(rows_b, cols_b, data, &B);

  int status = s21_sum_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_sum_matrix(void) {
  TCase *tcase_sum_matrix = tcase_create("TCase sum matrix");
  tcase_add_test(tcase_sum_matrix, test_sum_matrix_basic);
  tcase_add_test(tcase_sum_matrix, test_sum_matrix_different_rows);
  tcase_add_test(tcase_sum_matrix, test_sum_matrix_different_cols);

  Suite *suite_sum_matrix = suite_create("\033[94mS21_SUM_MATRIX\033[0m");
  suite_add_tcase(suite_sum_matrix, tcase_sum_matrix);

  return suite_sum_matrix;
}
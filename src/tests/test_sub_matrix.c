#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_sub_matrix_basic) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &expected_result);

  const double data_a[] = {7.6, 8.1, 5.4, 6.3, 4.4, 7.7, 8.8, 8.1, 4.0};
  const double data_b[] = {1.1, 2.1, 5.4, 2.2, 3.2, 1.9, 9.9, 6.1, 5.5};
  const double expected_data[] = {6.5, 6.0,  0.0, 4.1, 1.2,
                                  5.8, -1.1, 2.0, -1.5};

  FillMatrix(rows, cols, data_a, &A);
  FillMatrix(rows, cols, data_b, &B);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_sub_matrix(&A, &B, &result);
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

START_TEST(test_sub_different_rows_cols) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  int rows_a = 2, cols_a = 3;
  int rows_b = 3, cols_b = 3;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data_a[] = {7.6, 8.1, 5.4, 6.3, 4.4, 7.7, 8.8};
  const double data_b[] = {1.1, 2.1, 5.4, 2.2, 3.2, 1.9, 9.9, 6.1, 5.5};

  FillMatrix(rows_a, cols_a, data_a, &A);
  FillMatrix(rows_a, cols_a, data_b, &B);

  int status = s21_sub_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_different_rows) {
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

  int status = s21_sub_matrix(&A, &B, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_sub_matrix(void) {
  TCase *tcase_sub_matrix = tcase_create("TCase sub matrix");
  tcase_add_test(tcase_sub_matrix, test_sub_matrix_basic);
  tcase_add_test(tcase_sub_matrix, test_sub_different_rows_cols);
  tcase_add_test(tcase_sub_matrix, test_sub_matrix_different_rows);

  Suite *suite_sub_matrix = suite_create("S21_SUB_MATRIX");
  suite_add_tcase(suite_sub_matrix, tcase_sub_matrix);

  return suite_sub_matrix;
}
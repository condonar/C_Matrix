#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_eq_matrix_basic) {
  matrix_t A;
  matrix_t B;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(rows, cols, data, &B);

  int status = s21_eq_matrix(&A, &B);
  int expected_status = SUCCESS;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_not_equal) {
  matrix_t A;
  matrix_t B;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);

  const double data_a[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};
  const double data_b[] = {1.1, 2.0, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows, cols, data_a, &A);
  FillMatrix(rows, cols, data_b, &B);

  int status = s21_eq_matrix(&A, &B);
  int expected_status = FAILURE;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_different_rows_cols) {
  matrix_t A;
  matrix_t B;

  int rows_a = 3, cols_a = 3;
  int rows_b = 2, cols_b = 3;

  s21_create_matrix(rows_a, cols_a, &A);
  s21_create_matrix(rows_b, cols_b, &B);

  const double data_a[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};
  const double data_b[] = {1.1, 2.0, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};

  FillMatrix(rows_a, cols_a, data_a, &A);
  FillMatrix(rows_b, cols_b, data_b, &B);

  int status = s21_eq_matrix(&A, &B);
  int expected_status = FAILURE;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq_matrix(void) {
  TCase *tcase_eq_matrix = tcase_create("TCase eq matrix");
  tcase_add_test(tcase_eq_matrix, test_eq_matrix_basic);
  tcase_add_test(tcase_eq_matrix, test_eq_matrix_not_equal);
  tcase_add_test(tcase_eq_matrix, test_eq_matrix_different_rows_cols);

  Suite *suite_eq_matrix = suite_create("S21_EQ_MATRIX");
  suite_add_tcase(suite_eq_matrix, tcase_eq_matrix);

  return suite_eq_matrix;
}
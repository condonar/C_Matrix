#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_determinant_basic) {
  matrix_t A;
  double result;
  double expected_result = -40.0;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_determinant(&A, &result);
  int expected_status = OPERATION_OK;

  ck_assert_int_eq(status, expected_status);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_different_rows_cols) {
  matrix_t A;
  double result;

  int rows = 2;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_determinant(&A, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_min_rows_cols) {
  matrix_t A;
  double result;

  int rows = 1;
  int cols = 1;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {5.5};

  FillMatrix(rows, cols, data, &A);

  int status = s21_determinant(&A, &result);
  int expected_status = OPERATION_OK;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_two_two_matrix) {
  matrix_t A;
  double result;
  double expected_result = 11.0;

  int rows = 2;
  int cols = 2;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {5.0, 3.0, 8.0, 7.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_determinant(&A, &result);
  int expected_status = OPERATION_OK;

  ck_assert_int_eq(status, expected_status);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_five_five_matrix) {
  matrix_t A;
  double result;
  double expected_result = 20613.0;

  int rows = 5;
  int cols = 5;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {1.0, -4.0, 4.0, 2.0,  -8.0, 3.0, 4.0,  5.0, 5.0,
                         6.0, 5.0,  6.0, -7.0, 7.0,  5.0, -3.0, 3.0, -5.0,
                         0.0, 6.0,  0.0, 8.0,  2.0,  1.0, 0.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_determinant(&A, &result);
  int expected_status = OPERATION_OK;

  ck_assert_int_eq(status, expected_status);
  ck_assert_double_eq(result, expected_result);

  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_determinant(void) {
  TCase *tcase_determinant = tcase_create("TCase determinant");
  tcase_add_test(tcase_determinant, test_determinant_basic);
  tcase_add_test(tcase_determinant, test_determinant_different_rows_cols);
  tcase_add_test(tcase_determinant, test_determinant_min_rows_cols);
  tcase_add_test(tcase_determinant, test_determinant_two_two_matrix);
  tcase_add_test(tcase_determinant, test_determinant_five_five_matrix);

  Suite *suite_determinant = suite_create("\033[94mS21_DETERMINANT\033[0m");
  suite_add_tcase(suite_determinant, tcase_determinant);

  return suite_determinant;
}
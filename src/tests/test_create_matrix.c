#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_create_matrix_basic) {
  matrix_t result;
  int rows = 3;
  int cols = 3;
  int status = s21_create_matrix(rows, cols, &result);
  int exected_status = OPERATION_OK;

  ck_assert_int_eq(status, exected_status);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, cols);
  ck_assert_ptr_nonnull(result.matrix);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_create_zero_rows) {
  matrix_t result;
  int rows = 0;
  int cols = 3;
  int status = s21_create_matrix(rows, cols, &result);
  int exected_status = MATRIX_INCORRECT;

  ck_assert_int_eq(status, exected_status);
}
END_TEST

START_TEST(test_create_zero_columns) {
  matrix_t result;
  int rows = 3;
  int cols = 0;
  int status = s21_create_matrix(rows, cols, &result);
  int exected_status = MATRIX_INCORRECT;

  ck_assert_int_eq(status, exected_status);
}
END_TEST

Suite *suite_create_matrix(void) {
  TCase *tcase_create_matrix = tcase_create("TCase create matrix");
  tcase_add_test(tcase_create_matrix, test_create_matrix_basic);
  tcase_add_test(tcase_create_matrix, test_create_zero_rows);
  tcase_add_test(tcase_create_matrix, test_create_zero_columns);

  Suite *suite_create_matrix = suite_create("\033[94mS21_CREATE_MATRIX\033[0m");
  suite_add_tcase(suite_create_matrix, tcase_create_matrix);

  return suite_create_matrix;
}
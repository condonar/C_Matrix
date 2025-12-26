#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_transpose_basic) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 2;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(cols, rows, &expected_result);

  const double data[] = {1.0, 4.0, 2.0, 5.0, 3.0, 6.0};
  const double expected_data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(cols, rows, expected_data, &expected_result);

  int status = s21_transpose(&A, &result);
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

Suite *suite_transpose(void) {
  TCase *tcase_transpose = tcase_create("TCase transpose");
  tcase_add_test(tcase_transpose, test_transpose_basic);

  Suite *suite_transpose = suite_create("\033[94mS21_TRANSPOSE\033[0m");
  suite_add_tcase(suite_transpose, tcase_transpose);

  return suite_transpose;
}
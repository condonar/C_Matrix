#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_mult_number_basic) {
  matrix_t A;
  double number = 2.2;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &expected_result);

  const double data[] = {1.1, 2.1, 5.4, 2.3, 4.4, 7.7, 8.8, 8.1, 4.0};
  const double expected_data[] = {2.42,  4.62,  11.88, 5.06, 9.68,
                                  16.94, 19.36, 17.82, 8.8};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_mult_number(&A, number, &result);
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

Suite *suite_mult_number(void) {
  TCase *tcase_mult_number = tcase_create("TCase mult number");
  tcase_add_test(tcase_mult_number, test_mult_number_basic);

  Suite *suite_mult_number = suite_create("S21_MULT_NUMBER");
  suite_add_tcase(suite_mult_number, tcase_mult_number);

  return suite_mult_number;
}
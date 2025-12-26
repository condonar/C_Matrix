#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_calc_complements_basic) {
  matrix_t A;
  matrix_t result;
  matrix_t expected_result;

  int rows = 3;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &expected_result);

  const double data[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  const double expected_data[] = {0.0, 10.0, -20.0, 4.0, -14.0,
                                  8.0, -8.0, -2.0,  4.0};

  FillMatrix(rows, cols, data, &A);
  FillMatrix(rows, cols, expected_data, &expected_result);

  int status = s21_calc_complements(&A, &result);
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

START_TEST(test_calc_different_rows_cols) {
  matrix_t A;
  matrix_t result;

  int rows = 2;
  int cols = 3;

  s21_create_matrix(rows, cols, &A);

  const double data[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0};

  FillMatrix(rows, cols, data, &A);

  int status = s21_calc_complements(&A, &result);
  int expected_status = CALCULATION_ERROR;

  ck_assert_int_eq(status, expected_status);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_calc_complements(void) {
  TCase *tcase_calc_complements = tcase_create("TCase calc complements");
  tcase_add_test(tcase_calc_complements, test_calc_complements_basic);
  tcase_add_test(tcase_calc_complements, test_calc_different_rows_cols);

  Suite *suite_calc_complements =
      suite_create("\033[94mS21_CALC_COMPLEMENTS\033[0m");
  suite_add_tcase(suite_calc_complements, tcase_calc_complements);

  return suite_calc_complements;
}
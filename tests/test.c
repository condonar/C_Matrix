#include "test.h"

int main(void) {
  Suite *suite_array[] = {suite_create_matrix(),
                          suite_eq_matrix(),
                          suite_sum_matrix(),
                          suite_sub_matrix(),
                          suite_mult_number(),
                          suite_mult_matrix(),
                          suite_transpose(),
                          suite_calc_complements(),
                          suite_determinant(),
                          suite_inverse_matrix(),
                          NULL};

  for (int i = 0; suite_array[i] != NULL; i++) {
    SRunner *runner = srunner_create(suite_array[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}
#include <check.h>
#include <stdlib.h>
#include "suites.h"

Suite * make_master_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("All Test Suites");
    tc_core = tcase_create("Core");
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

int main(void){
    int number_failed = 0;
    SRunner *sr;

    sr = srunner_create(make_master_suite());
    srunner_add_suite(sr, file_suite());
    
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
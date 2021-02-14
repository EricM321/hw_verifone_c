#include <check.h>
#include "../src/fileIO.h"
#include <stdlib.h>


START_TEST(test_should_load_validation_file){
    char validFile[100] = {0};
    loadValidationFile(validFile, "test/resources/test.txt");
    ck_assert_str_eq(validFile, ";;;");
}
END_TEST

/*START_TEST(test_should_load_validation_file){
    ck_assert_str_eq(loadValidationFile(), ";;;");
}
END_TEST*/

Suite * file_suite(void){
    Suite *s;
    TCase *tc_core;
    
    s = suite_create("File IO");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_should_load_validation_file);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void){
    int number_failed = 0;
    Suite *s;
    SRunner *sr;
    
    s = file_suite();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/fileIO.h"

START_TEST(test_should_load_actual_validation_file){
    char validationFile[89] = "400000000000;499999999999;VISA;50000000;59999999;MASTERCARD;67000000;67999999;MAESTRO;";
    char validFile[100] = {0};
    loadValidationFile(validFile, "src/file.txt");
    ck_assert_str_eq(validFile, validationFile);
}
END_TEST

START_TEST(test_should_load_test_file){
    char validFile[100] = {0};
    loadValidationFile(validFile, "test/resources/test.txt");
    ck_assert_str_eq(validFile, ";;;");
}
END_TEST

START_TEST(test_should_save_file){
    saveFile("5000999900000000;","MASTERCARD;","10.23;", "test/resources/saveTest.txt");
    
    char validFile[100] = {0};
    loadValidationFile(validFile, "test/resources/saveTest.txt");
    ck_assert_str_eq(validFile, "5000999900000000;MASTERCARD;10.23;");
    remove("test/resources/saveTest.txt");
}
END_TEST

Suite * file_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("File IO");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_should_load_actual_validation_file);
    tcase_add_test(tc_core, test_should_load_test_file);
    tcase_add_test(tc_core, test_should_save_file);
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/fileIO.h"

START_TEST(test_should_load_test_file){
    char validFile[100] = {0};
    loadValidationFile(validFile, "test/resources/test.txt");
    ck_assert_str_eq(validFile, ";;;");
}
END_TEST

START_TEST(test_should_save_file){
    saveFile("1;","VISA;","10.23;", "test/resources/saveTest.txt");
    
    char validFile[100] = {0};
    loadValidationFile(validFile, "test/resources/saveTest.txt");
    ck_assert_str_eq(validFile, "1;VISA;10.23;\n");
    remove("test/resources/saveTest.txt");
}
END_TEST

Suite * file_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("File IO");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_should_load_test_file);
    tcase_add_test(tc_core, test_should_save_file);
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

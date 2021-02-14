#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/userInput.h"

START_TEST(test_should_give_correct_card_number){
    ck_assert(validateCardNumber("12"));
}
END_TEST

START_TEST(test_should_give_correct_amount){
    ck_assert(validateAmount("12"));
}
END_TEST

Suite * input_validation_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("Input Validation");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_should_give_correct_card_number);
    tcase_add_test(tc_core, test_should_give_correct_amount);
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

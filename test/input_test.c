#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/userInput.h"

START_TEST(test_card_number_should_be_valid){
    char cardNum[18] = "1234567890123456\n\0";
    ck_assert(validateCardNumber(cardNum, (char *)(&cardNum + 1) - 1));
}
END_TEST

START_TEST(test_card_number_should_be_too_long){
    char cardNum[18] = "12345678901234564\n";
    ck_assert(!validateCardNumber(cardNum, (char *)(&cardNum + 1) - 1));
}
END_TEST

START_TEST(test_card_number_should_be_too_short){
    char cardNum[18] = "123456789012345\n\0";
    ck_assert(!validateCardNumber(cardNum, (char *)(&cardNum + 1) - 1));
}
END_TEST

START_TEST(test_card_number_should_be_invalid){
    char cardNum[18] = "12345T7890123456\n\0";
    ck_assert(!validateCardNumber(cardNum, (char *)(&cardNum + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_be_valid){
    char amount[9] = "1200.00\n\0";
    ck_assert(validateAmount(amount, (char *)(&amount + 1) - 1));

    char amount2[9] = "200.00\n\0";
    ck_assert(validateAmount(amount2, (char *)(&amount2 + 1) - 1));

    char amount3[9] = "20.00\n\0";
    ck_assert(validateAmount(amount3, (char *)(&amount3 + 1) - 1));

    char amount4[9] = "2.00\n\0";
    ck_assert(validateAmount(amount4, (char *)(&amount4 + 1) - 1));

    char amount5[9] = "0.00\n\0";
    ck_assert(validateAmount(amount5, (char *)(&amount5 + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_be_invalid){
    char amount[9] = "12T0.00\n\0";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_have_too_many_decimal_points){
    char amount[9] = "12.0.00\n\0";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_have_no_decimal_points){
    char amount[9] = "120000\n\0";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_have_incorrect_number_of_decimal_places){
    char amount[9] = "120.000\n\0";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_have_incorrect_format){
    char amount[9] = ".00\n\0";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

START_TEST(test_amount_should_be_too_large){
    char amount[9] = "12000.00\n";
    ck_assert(!validateAmount(amount, (char *)(&amount + 1) - 1));
}
END_TEST

Suite * input_validation_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("Input Validation");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_card_number_should_be_valid);
    tcase_add_test(tc_core, test_card_number_should_be_invalid);
    tcase_add_test(tc_core, test_card_number_should_be_too_long);
    tcase_add_test(tc_core, test_card_number_should_be_too_short);
    tcase_add_test(tc_core, test_amount_should_be_valid);
    tcase_add_test(tc_core, test_amount_should_be_invalid);
    tcase_add_test(tc_core, test_amount_should_have_too_many_decimal_points);
    tcase_add_test(tc_core, test_amount_should_have_no_decimal_points);
    tcase_add_test(tc_core, test_amount_should_have_incorrect_number_of_decimal_places);
    tcase_add_test(tc_core, test_amount_should_have_incorrect_format);
    tcase_add_test(tc_core, test_amount_should_be_too_large);
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

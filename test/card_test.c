#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/cardCheck.h"

char validationFile[88] = "400000000000;499999999999;VISA;50000000;59999999;MASTERCARD;67000000;67999999;MAESTRO;";

START_TEST(test_card_number_should_be_VISA){
    char type[10] = {0};
    getCardType(validationFile, (char *)(&validationFile + 1) - 1, "4000000000000000\n\0", type);
    ck_assert_str_eq(type , "VISA");
}
END_TEST

START_TEST(test_card_number_should_be_MASTERCARD){
    char type[10] = {0};
    getCardType(validationFile, (char *)(&validationFile + 1) - 1, "5000000000000000\n\0", type);
    ck_assert_str_eq(type , "MASTERCARD");

    getCardType(validationFile, (char *)(&validationFile + 1) - 1, "5123467890123456\n\0", type);
    ck_assert_str_eq(type , "MASTERCARD");
}
END_TEST

START_TEST(test_card_number_should_be_MAESTRO){
    char type[10] = {0};
    getCardType(validationFile, (char *)(&validationFile + 1) - 1, "6700000000000000\n\0", type);
    ck_assert_str_eq(type , "MAESTRO");
}
END_TEST

START_TEST(test_card_numbers_should_be_invalid){
    char type[10] = {0};
    
    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "1700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "2700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "3700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "6000000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "7700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "8700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "9700000000000000\n\0", type));

    ck_assert(!getCardType(validationFile, (char *)(&validationFile + 1) - 1, "3712456890123456\n\0", type));
}
END_TEST

Suite * card_validation_suite(void){
    Suite *suite;
    TCase *tc_core;
    
    suite = suite_create("Validate Card");
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_card_number_should_be_VISA);
    tcase_add_test(tc_core, test_card_number_should_be_MASTERCARD);
    tcase_add_test(tc_core, test_card_number_should_be_MAESTRO);
    tcase_add_test(tc_core, test_card_numbers_should_be_invalid);
    suite_add_tcase(suite, tc_core);
    
    return suite;
}

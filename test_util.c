/**
 * Test Util
 * Nolan Lau
 * Copyright (c) Pax Labs, Inc. 2018.
 */

#include "unity.h"
#include "util.h"
#include <string.h>
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_util_int_to_string(void)
{
    char test_str[10];
    intToStr(123, test_str, 4);

    TEST_ASSERT_EQUAL_STRING("0123", test_str);
}


void test_util_reversing_a_string(void)
{
    char test_str[] = "abcdef";

    reverse(test_str, strlen(test_str));

    TEST_ASSERT_EQUAL_STRING("fedcba", test_str);
}


void test_util_float_to_string_three_decimals_1(void)
{
    float test_float = 3.147;
    char test_str[10];

    ftoa(test_float, test_str);

    TEST_ASSERT_EQUAL_STRING("3.147", test_str);
}


void test_util_float_to_string_three_decimals_2(void)
{
    float test_float = 3.148;
    char test_str[7];

    ftoa(test_float, test_str);

    TEST_ASSERT_EQUAL_STRING("3.148", test_str);
}

void test_util_int_to_hex(void)
{
    TEST_ASSERT_EQUAL_HEX8('F', intToHex(15));

    TEST_ASSERT_EQUAL_HEX8('0', intToHex(0));

    TEST_ASSERT_EQUAL_HEX8('A', intToHex(10));
}

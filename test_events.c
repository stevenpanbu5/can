/**
 * Test Events
 * Nolan Lau
 * Copyright (c) Pax Labs, Inc. 2018.
*/

#include "unity.h"
#include "events.h"
#include "../util/ringbuf.h"

void setUp(void)
{
    // Events should be inserted as a '1' in its respective bit field
    events_put(EVENTS_PUSH_SW_PRESSED_e);
    events_put(EVENTS_DEVICE_CONNECTED_e);
    events_put(EVENTS_USB_CONNECTED_e);
    events_put(EVENTS_DEVICE_ISENSE_CONNECTED_e);

    // Cycle Ring Buffer For The Different Events
    events_manager();
    events_manager();
    events_manager();
    events_manager();
}

void tearDown(void)
{
}

void test_events_get_set_events(void)
{
    // Events should return a '1'
    TEST_ASSERT(events_get(EVENTS_PUSH_SW_PRESSED_e));
    TEST_ASSERT(events_get(EVENTS_DEVICE_CONNECTED_e));
    TEST_ASSERT(events_get(EVENTS_USB_CONNECTED_e));
    TEST_ASSERT(events_get(EVENTS_DEVICE_ISENSE_CONNECTED_e));
}

void test_events_get_not_set_events(void)
{
    // Events should be inserted as a '0' in its respective bit field
    events_put(EVENTS_PUSH_SW_DEPRESSED_e);
    events_put(EVENTS_DEVICE_DISCONNECTED_e);
    events_put(EVENTS_USB_DISCONNECTED_e);
    events_put(EVENTS_DEVICE_ISENSE_DISCONNECTED_e);

    // Cycle Ring Buffer For The Different Events
    events_manager();
    events_manager();
    events_manager();
    events_manager();

    // Events should return a 0
    TEST_ASSERT_UNLESS(events_get(EVENTS_PUSH_SW_PRESSED_e));
    TEST_ASSERT_UNLESS(events_get(EVENTS_DEVICE_CONNECTED_e));
    TEST_ASSERT_UNLESS(events_get(EVENTS_USB_CONNECTED_e));
    TEST_ASSERT_UNLESS(events_get(EVENTS_DEVICE_ISENSE_CONNECTED_e));

    //cancancan- push with git url
    //canhttp - push with http url
}

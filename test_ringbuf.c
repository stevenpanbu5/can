/**
 * Test Ringbuf
 * Nolan Lau
 * Copyright (c) Pax Labs, Inc. 2018.
 */

#include "unity.h"
#include "ringbuf.h"

ring_buf_t test_buf;

void setUp(void)
{
    ring_buf_init(&test_buf);

    for(int i = 0; i < BUFFER_SIZE-1; i++)
    {
        ring_buf_put(&test_buf, i);
    }
}

void tearDown(void)
{
}

void test_ringbuf_removal(void)
{
    // Iterate though buffer and check if it was inserted in order
    for(int i = 0; i < BUFFER_SIZE - 1; i++)
    {
        TEST_ASSERT_EQUAL_UINT8(i, ring_buf_get(&test_buf));
    }
}

void test_ringbuf_empty_true(void)
{
    // Remove all content from buffer
    for(int i = 0; i < BUFFER_SIZE-1; i++)
    {
        ring_buf_get(&test_buf);
    }

    TEST_ASSERT_TRUE(ring_buf_empty(&test_buf));
}

void test_ringbuf_empty_false(void)
{
    // Leave an item in buffer
    for(int i = 0; i < BUFFER_SIZE-2; i++)
    {
        ring_buf_get(&test_buf);
    }

    TEST_ASSERT_FALSE(ring_buf_empty(&test_buf));
}

void test_ringbuf_removal_reinsert(void)
{
    // Remove Half of Buffer
    for(int i = 0; i < (BUFFER_SIZE / 2); i++)
    {
        TEST_ASSERT_EQUAL_UINT8(i, ring_buf_get(&test_buf));
    }

    // Insert New Values in Half the Buffer
    for(int i = 0; i < (BUFFER_SIZE / 2) - 1; i++)
    {
        static int j = 100;
        ring_buf_put(&test_buf, j);
        j++;
    }

    for(int i = 0; i < (BUFFER_SIZE / 2); i++)
    {
        static int j = 17;
        TEST_ASSERT_EQUAL_UINT8(j, ring_buf_get(&test_buf));
        j++;
    }

    for(int i = 0; i < (BUFFER_SIZE / 2 ) - 1; i++)
    {
        static int j = 100;
        TEST_ASSERT_EQUAL_UINT8(j, ring_buf_get(&test_buf));
        j++;
    }
}

#include "gtest/gtest.h"
#include "uclib/thread.h"
#include "uclib/mutex.h"
#include "uclib/date_time.h"

struct share_data_t {
    mutex_t* mutex;
    int count;
};

#define NR 100
#define COUNT 1000

static void* inc(void* args) {
    share_data_t* data = (share_data_t*)args;
    msleep(100);
    for(int i = 0 ; i < COUNT; i++) {
        mutex_lock(data->mutex);
        data->count++;
        mutex_unlock(data->mutex);
    }   

    return NULL;
}

TEST(thread, basic) {
    share_data_t data;
    data.mutex = mutex_create();
    data.count = 0;

    size_t i = 0;
    thread_t* threads[NR];

    for(i = 0; i < NR; i++) {
        threads[i] = thread_create(inc, &data);
        thread_start(threads[i]);
    }   
    for(i = 0; i < NR; i++) {
        thread_join(threads[i]);
        thread_destroy(threads[i]);
    }
    ASSERT_EQ(data.count, NR*COUNT);

    mutex_destroy(data.mutex);
}

static void* fastquit(void* args) {
  return NULL;
}

TEST(thread, fastquit) {
    size_t i = 0;
    thread_t* threads[NR];

    for(i = 0; i < NR; i++) {
        threads[i] = thread_create(fastquit, NULL);
        thread_start(threads[i]);
    }   
    for(i = 0; i < NR; i++) {
        thread_join(threads[i]);
        thread_destroy(threads[i]);
    }
}


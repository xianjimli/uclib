/*
 * 功能说明：
 *     1.mutex_t类的实现。
 *
 * 修改历史：
 *     1.2017-5-6 李先静 创建。
 */

#include "mutex.h"

#ifdef WIN32
#include "Windows.h"
#define mutex_handle_t HANDLE
#else
#include "pthread.h"
#define mutex_handle_t pthread_mutex_t
#endif

struct _mutex_t {
  bool_t created;
  mutex_handle_t mutex;
};

mutex_t* mutex_create() {
  mutex_t* mutex = (mutex_t*)calloc(1, sizeof(mutex_t));
  return_value_if_fail(mutex != NULL, NULL);
#ifdef WIN32
  mutex->mutex = CreateMutex(NULL, FALSE, NULL);
  mutex->created = mutex->mutex != NULL;
#else
  mutex->created = 0 == pthread_mutex_init(&(mutex->mutex), NULL);
#endif

  return mutex;
}

bool_t mutex_lock(mutex_t* mutex) {
  return_value_if_fail(mutex != NULL && mutex->created, FALSE);

#ifdef WIN32
  WaitForSingleObject(mutex->mutex, INFINITE);
#else
  pthread_mutex_lock(&(mutex->mutex));
#endif

  return TRUE;
}

bool_t mutex_unlock(mutex_t* mutex) {
  return_value_if_fail(mutex != NULL && mutex->created, FALSE);

#ifdef WIN32
  ReleaseMutex(mutex->mutex);
#else
  pthread_mutex_unlock(&(mutex->mutex));
#endif

  return TRUE;
}

void mutex_destroy(mutex_t* mutex) {
  return_if_fail(mutex != NULL && mutex->created);

#ifdef WIN32
  CloseHandle(mutex->mutex);
#else
  pthread_mutex_destroy(&(mutex->mutex));
#endif
  mutex->created = FALSE;

  free(mutex);
}

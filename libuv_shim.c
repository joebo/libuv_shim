#include <stdio.h>
#include "uv.h"

#define ASSERT(expr)                                      \
 do {                                                     \
  if (!(expr)) {                                          \
    fprintf(stderr,                                       \
            "Assertion failed in %s on line %d: %s\n",    \
            __FILE__,                                     \
            __LINE__,                                     \
            #expr);                                       \
    abort();                                              \
  }                                                       \
 } while (0)

       
__declspec(dllexport) int add(int a, int b)
{
  return (a + b);
}

__declspec(dllexport) void* timer_create_default()
{
    uv_timer_t *timer = (uv_timer_t*)malloc(sizeof(uv_timer_t));
    int r = uv_timer_init(uv_default_loop(), timer);
    ASSERT(r == 0);
    return timer;
}

static void once_cb(uv_timer_t* handle) {
    /*
  printf("ONCE_CB %d\n", once_cb_called);

  ASSERT(handle != NULL);
  ASSERT(0 == uv_is_active((uv_handle_t*) handle));

  once_cb_called++;

  uv_close((uv_handle_t*)handle, once_close_cb);

    */
    printf("TIMER!!: hi\n");
  
}

__declspec(dllexport) void timer_start(uv_timer_t *timer)
{
    int r = uv_timer_start(timer, once_cb, 1, 0);
    uv_run(uv_default_loop(), UV_RUN_ONCE);
    ASSERT(r == 0);
}

__declspec(dllexport) void timer_start_cb(uv_timer_t *timer, void*cb)
{
    int r = uv_timer_start(timer, cb, 1, 0);
    uv_run(uv_default_loop(), UV_RUN_ONCE);
    ASSERT(r == 0);
}

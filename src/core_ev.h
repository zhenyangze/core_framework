#ifndef __CORE_EV__
#define __CORE_EV__

/* 独立头文件 */
#define EV_STANDALONE 1

/* 关闭3.x版本兼容选择特性 */
#define EV_COMPAT3 0

#define EV_MULTIPLICITY 1

/* 开启优先级特性 */
#define EV_MAXPRI 2
#define EV_MINPRI -2

/* 单进程/单线程模型 */
#define EV_NO_SMP 1
#define EV_NO_THREADS 1

/* eventfd 与 signalfd */
#if defined(__linux)  || defined(__linux__)
	#define EV_USE_INOTIFY 1
	#define EV_USE_SIGNALFD 1
	#define EV_USE_EVENTFD 1
#endif

/* 开启Time缓存 */
#define EV_USE_4HEAP 1
#define EV_HEAP_CACHE_AT 1

/* 使用自带的floor计算浮点数 */
#define EV_USE_FLOOR 1

#define EV_COMMON void *co;

#include <ev.h>

#define EV_ONCE struct ev_once *once

#define EV_ONCE_ struct ev_once *once,

struct ev_once {
	ev_io *io;
	ev_timer *timer;
	void *data;
	void (*cb)(EV_ONCE_ void *arg, int revents);
};

/* 获取用户数据 */
#define ev_get_watcher_userdata(watcher) ((watcher)->co ? (watcher)->co: NULL)

/* 判断是否包含用户数据 */
#define ev_have_watcher_userdata(watcher) ((watcher)->co ? (watcher)->co : NULL)

/* 设置用户数据的宏 */
#define ev_set_watcher_userdata(watcher, userdata) ((watcher)->co = (userdata))


void ev_once(int socket, int events, ev_tstamp timeout, void (*cb)(EV_ONCE_ void *arg, int revents), void *args);

#endif
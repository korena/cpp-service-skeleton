#ifndef SERVICE_DBG_H
#define SERVICE_DBG_H

#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>


#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
    __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None": strerror(errno))


#define log_err(M, ...) fprintf(stderr,\
    "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,\
    clean_errno(), ##__VA_ARGS__)


#define log_warn(M, ...) fprintf(stderr,\
    "[WARN] (%s:%d: errno: %s) " M "\n",\
    __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
    __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) {\
  log_err(M, ##__VA_ARGS__); errno=0; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__);\
  errno=0; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
  errno=0; }


#endif //SERVICE_DBG_H
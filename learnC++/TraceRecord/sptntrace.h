#ifndef _SPTN_TRACE_H
#define _SPTN_TRACE_H

typedef char BYTE;
typedef int DWORD;

#define LEVEL_INFO 1
#define LEVEL_DEBUG 2
#define LEVEL_ERROR 3
void sptn_trace_record(DWORD dwCurrentLevel, const void *fmt, ...);
void sptn_trace_show(DWORD begin = 0);
void sptn_trace_clear();
#define SPTN_TRACE_DEBUG(...) sptn_trace_record(LEVEL_DEBUG, __VA_ARGS__)
#define SPTN_TRACE_INFO(...) sptn_trace_record(LEVEL_INFO, __VA_ARGS__)
#define SPTN_TRACE_ERROR(...) sptn_trace_record(LEVEL_ERROR, __VA_ARGS__)

#endif

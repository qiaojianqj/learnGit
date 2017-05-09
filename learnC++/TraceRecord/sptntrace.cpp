#include "sptntrace.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TRACE_LINE 1000
#define TRACE_LINE_LENGTH 160

BYTE g_ucTraceBuffer[TRACE_LINE][TRACE_LINE_LENGTH] = {0};
BYTE g_acLine[TRACE_LINE_LENGTH];
DWORD g_dwTraceLine = 0;
DWORD g_dwTraceFlag = LEVEL_INFO;

void sptn_trace_record(DWORD dwCurrentLevel, const void *fmt, ...)
{
	if(dwCurrentLevel < g_dwTraceFlag){
		return;
	}
	memset(g_acLine, 0, TRACE_LINE_LENGTH);
	if(TRACE_LINE <= g_dwTraceLine){
		g_dwTraceLine = 0;	
	}
	va_list ap;
	va_start(ap, fmt);
	vsprintf((char *)g_acLine, (const char *)fmt, ap);
	va_end(ap);
	memset(g_ucTraceBuffer[g_dwTraceLine], 0, TRACE_LINE_LENGTH);
	memcpy(g_ucTraceBuffer[g_dwTraceLine], g_acLine, TRACE_LINE_LENGTH);
	g_dwTraceLine++;
}

void sptn_trace_show(DWORD begin)
{
	DWORD dwIndex = 0;
	printf("Current sptn trace line: %d\n", g_dwTraceLine);
	for(dwIndex = begin; dwIndex < TRACE_LINE; dwIndex++)
	{
		if(0 != g_ucTraceBuffer[dwIndex][0]){
			printf("[%d]: %s\n", dwIndex, g_ucTraceBuffer[dwIndex]);
		}
	}
}

void sptn_trace_clear()
{
	g_dwTraceLine = 0;
	memset((char *)g_ucTraceBuffer, 0, TRACE_LINE*TRACE_LINE_LENGTH);
}

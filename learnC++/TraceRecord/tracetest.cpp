#include "sptntrace.h"

int main()
{
	char arr[32] = "what fuck!";
	SPTN_TRACE_ERROR("trace error print %s\n", arr);
	SPTN_TRACE_DEBUG("trace debug print %s\n",arr);
	SPTN_TRACE_INFO("trace info print %s\n",arr);
	sptn_trace_show();
	sptn_trace_clear();
	sptn_trace_show();
	return 0;
}

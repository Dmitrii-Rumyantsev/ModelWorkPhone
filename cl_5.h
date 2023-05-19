#ifndef __cl_5__H
#define __cl_5__H
#include "cl_base.h"
#include "cl_base.h"
class cl_5 : public cl_base {
public:
	cl_5(cl_base* p_head_object, string s_name);
	void signal_5(string& msg);
	void handler_5(string msg);
};
#endif
#ifndef __cl_4__H
#define __cl_4__H
#include "cl_base.h"
class cl_4 : public cl_base {
public:
	cl_4(cl_base* p_head_object, string s_name);
	void signal_4(string& msg);
	void handler_4(string msg);
};
#endif
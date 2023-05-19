#ifndef __cl_6__H
#define __cl_6__H
#include "cl_base.h"
class cl_6 : public cl_base {
public:
	cl_6(cl_base* p_head_object, string s_name);
	void signal_6(string& msg);
	void handler_6(string msg);
};
#endif

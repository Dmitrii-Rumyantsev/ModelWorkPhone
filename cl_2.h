#ifndef __cl_2__H
#define __cl_2__H
#include "cl_base.h"
class cl_2 : public cl_base {
public:
	cl_2(cl_base* p_head_object, string s_name);
	void signal_2(string& msg);
	void handler_2(string msg);
};
#endif
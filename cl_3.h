#ifndef __cl_3__H
#define __cl_3__H
#include "cl_base.h"
#include "set"



class cl_3 : public cl_base {
public:
	cl_3(cl_base* p_head_object, string s_name);
	void signal_3(string& msg);
	void handler_3(string msg);
};
#endif
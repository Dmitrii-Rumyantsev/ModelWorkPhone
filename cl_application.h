#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"
class cl_application : public cl_base {
public:
	cl_application();
	cl_application(cl_base* head_object,string s_name);
	void build_tree_objects();
	int exec_app();
	void signal_1(string&);
	void handler_1(string);
};
#endif
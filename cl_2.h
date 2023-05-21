#ifndef __cl_2__H
#define __cl_2__H
#include "cl_base.h"
//Ввод данных
class cl_2 : public cl_base {
public:
	cl_2(cl_base* p_head_object, string s_name);
	void signal_input_data(string&);
};
#endif
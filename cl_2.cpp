#include "cl_2.h"

#include "cl_3.h"

cl_2::cl_2(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
	this->number = 2;
}
void cl_2::signal_2(string& msg) {
	getline(cin, msg);
	if (msg == "End of phones") {
		this->flag = false;
		return;
	}
	heads->get_sub_object("sys")->emit_signal((TYPE_SIGNAL)(&cl_3::signal_3), msg);
}
void cl_2::handler_2(string msg) {
	if(this->flag)
		cout << "Signal to ";
}
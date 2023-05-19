#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_2.h"

cl_3::cl_3(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
	this->number = 3;

}
void cl_3::signal_3(string& msg) {
	bool found = std::find(numbers.begin(), numbers.end(), msg) != numbers.end();
	if(!found)
	{
		if (msg.size() == 7) {
			numbers.push_back(msg);
			cl_base* obj = new cl_base(this, msg);
			heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_2::signal_2), obj, (TYPE_HANDLER)(&cl_2::handler_2));

			heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_3::signal_3), obj, (TYPE_HANDLER)(&cl_3::handler_3));
			heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_4::signal_4), obj, (TYPE_HANDLER)(&cl_4::handler_4));

			heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_5::signal_5), obj, (TYPE_HANDLER)(&cl_5::handler_5));
		}
	}
}
void cl_3::handler_3(string msg) {
	cout << "Signal to " << get_absolute_way() << " Text: " << msg << endl;
}
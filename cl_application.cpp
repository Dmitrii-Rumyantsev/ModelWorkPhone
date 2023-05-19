#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
cl_application::cl_application() :cl_base(heads, "sys")
{
	number = 1;
}

cl_application::cl_application(cl_base* head_object,string s_name) : cl_base(head_object, s_name) {
	number = 1;
}
void cl_application::build_tree_objects() {
	new cl_2(this, "read");
	new cl_3(this, "pult");
	new cl_4(this, "print");
	new cl_5(this, "phone");
	string command;
	while (this->flag)
	{
		heads->get_sub_object("sys")->emit_signal((TYPE_SIGNAL)(&cl_2::signal_2), command);
	}
	heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_2::signal_2), heads->get_sub_object("read"), (TYPE_HANDLER)(&cl_2::handler_2));
	heads->get_sub_object("read")->set_connection((TYPE_SIGNAL)(&cl_2::signal_2), heads->get_sub_object("pult"), (TYPE_HANDLER)(&cl_3::handler_3));
	heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_3::signal_3), heads->get_sub_object("pult"), (TYPE_HANDLER)(&cl_3::handler_3));
	heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_4::signal_4), heads->get_sub_object("print"), (TYPE_HANDLER)(&cl_4::handler_4));
	heads->get_sub_object("sys")->set_connection((TYPE_SIGNAL)(&cl_5::	signal_5), heads->get_sub_object("phone"), (TYPE_HANDLER)(&cl_5::handler_5));


	
	
	heads->get_sub_object("read")->set_connection((TYPE_SIGNAL)(&cl_2::signal_2), heads->get_sub_object("print"), (TYPE_HANDLER)(&cl_4::handler_4));
	heads->get_sub_object("read")->set_connection((TYPE_SIGNAL)(&cl_2::signal_2), heads->get_sub_object("phone"), (TYPE_HANDLER)(&cl_5::handler_5));


	heads->get_sub_object("pult")->set_connection((TYPE_SIGNAL)(&cl_3::signal_3), heads->get_sub_object("pult"), (TYPE_HANDLER)(&cl_3::handler_3));
	heads->get_sub_object("pult")->set_connection((TYPE_SIGNAL)(&cl_3::signal_3), heads->get_sub_object("print"), (TYPE_HANDLER)(&cl_4::handler_4));
	heads->get_sub_object("pult")->set_connection((TYPE_SIGNAL)(&cl_3::signal_3), heads->get_sub_object("phone"), (TYPE_HANDLER)(&cl_5::handler_5));

	heads->get_sub_object("print")->set_connection((TYPE_SIGNAL)(&cl_4::signal_4), heads->get_sub_object("print"), (TYPE_HANDLER)(&cl_4::handler_4));
	heads->get_sub_object("print")->set_connection((TYPE_SIGNAL)(&cl_4::signal_4), heads->get_sub_object("phone"), (TYPE_HANDLER)(&cl_5::handler_5));

	heads->get_sub_object("phone")->set_connection((TYPE_SIGNAL)(&cl_5::signal_5), heads->get_sub_object("phone"), (TYPE_HANDLER)(&cl_5::handler_5));

}

int cl_application::exec_app() {
	string command;
	do
	{
		getline(cin, command);
		heads->get_sub_object("sys")->emit_signal((TYPE_SIGNAL)(&cl_2::signal_2), command);
	}
	while (command != "SHOWTREE");
	return 0;
}
void cl_application::signal_1(string& msg) {
	cout << "Signal from " << get_absolute_way() << endl;
	msg = msg + " (class:1)";
}
void cl_application::handler_1(string msg) {
	cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}


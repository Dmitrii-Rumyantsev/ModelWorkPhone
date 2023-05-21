#include "cl_2.h"
#include "cl_4.h"
#include "cl_3.h"

cl_2::cl_2(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
	this->number = 2;
}
void cl_2::signal_input_data(string& msg) {
    getline(cin, c_cmd);
    if(c_cmd == "End of phones"){
        return;
    }
    else if (c_cmd.size() == 7  &&!get_sub_object("pult")->search_object(c_cmd)) {
        cl_3 *obj = new cl_3(get_sub_object("pult"), c_cmd);
        obj->set_connection(SIGNAL_D(cl_4::signal_4), obj, HANDLER_D(cl_4::handler_4));
    }
    else if(c_cmd.substr(0,12) == "Call request"){
        emit_signal(SIGNAL_D(cl_3::signal_3),c_cmd);
    }
    else if(c_cmd.substr(0,25) == "Display phone information"){
        emit_signal(SIGNAL_D(cl_3::signal_3),c_cmd);
    }
    else if(c_cmd.substr(0,33) == "Display system status information"){
        emit_signal(SIGNAL_D(cl_4::signal_4),c_cmd);
    }
}

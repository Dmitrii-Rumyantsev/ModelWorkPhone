#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"


cl_application::cl_application(cl_base* head_object,string s_name) : cl_base(head_object, s_name) {
	number = 1;
}
void cl_application::build_tree_objects() {
    cl_base* p_sub = this;
	p_sub= new cl_2(this, "read");
	p_sub = new cl_3(this, "pult");
    p_sub = new cl_4(this, "prints");
    p_sub = new cl_5(this, "phones");
    setFullReadiness();
    string s_msg;
    c_cmd = "";
    while(c_cmd!= "End of phones") {
        emit_signal(SIGNAL_D(cl_2::signal_input_data), c_cmd);
    }
    //установка связей
    //================================================================
    // Связь для ввода комманды Call request «номер отправителя» «номер абонента» «продолжительность разговора в секундах»
    //================================================================
    get_sub_object("pult")->set_connection(SIGNAL_D(cl_3::signal_3), get_sub_object("pult"),HANDLER_D(cl_3::signal_3));
    get_sub_object("pult")->set_connection(SIGNAL_D(cl_3::signal_3), get_sub_object("phone"),HANDLER_D(cl_4::signal_4));
    //================================================================
    // Связь для ввода комманды Display phone information «номер телефона»
    //================================================================
    get_sub_object("pult")->set_connection(SIGNAL_D(cl_3::signal_3), get_sub_object("pult"),HANDLER_D(cl_3::signal_3));
    get_sub_object("pult")->set_connection(SIGNAL_D(cl_3::signal_3), get_sub_object("phone"),HANDLER_D(cl_4::signal_4));
    get_sub_object("phone")->set_connection(SIGNAL_D(cl_5::signal_5), get_sub_object("prints"),HANDLER_D(cl_4::signal_4));
}

int cl_application::exec_app() {
	string command = "";
	do
	{
        tact++;
        emit_signal(SIGNAL_D(cl_2::signal_input_data),command);
	}
	while (c_cmd != "SHOWTREE" || c_cmd != "Turn off the system");
	return 0;
}

//нужен метод для конца ввода
void cl_application::signal_reader_to_all(string &) {

}

void cl_application::handler_1(string ) {}


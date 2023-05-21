#include "cl_4.h"
#include "cl_5.h"
cl_4::cl_4(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
	this->number = 4;
}
void cl_4::signal_4(string& msg) {
    if (msg.substr(0, 25) == "Display phone information") {
        cout << "Phone log: " << msg.substr(25) << endl;
    } else if (msg.substr(0, 25) == "Display the system status") {
        cout << "System status: " << msg.substr(25) << endl;
    }
}

void cl_4::handler_4(string msg) {
    if (msg.substr(0, 12) == "Call request") {
        size_t firstSpacePos = msg.find(' ');
        size_t secondSpacePos = msg.find(' ', firstSpacePos + 1);

        // Извлекаем значения first, second и time из строки
        string first = msg.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
        string second = msg.substr(secondSpacePos + 1);
        cout << "Call from " << first << " to " << second << ", talk: " << time << endl;
    } else if (msg.substr(0, 25) == "Display phone information") {
        string number = msg.substr(25);
        emit_signal(SIGNAL_D(cl_5::signal_5), number);
    } else if (msg.substr(0, 25) == "Display the system status") {
        emit_signal(SIGNAL_D(cl_5::signal_5), msg);
    }
}

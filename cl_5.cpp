#include "cl_5.h"
cl_5::cl_5(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
	this->number = 5;
}
void cl_5::signal_5(string& msg) {
	cout << "Signal from " << get_absolute_way() << endl;
	msg = msg + " (class: 5)";
}
void cl_5::handler_5(string msg) {
    if(msg.substr(0,12) == "Call request") {
        size_t firstSpacePos = msg.find(' ');
        size_t secondSpacePos = msg.find(' ', firstSpacePos + 1);

        // Извлекаем значения first, second и time из строки
        string first = msg.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
        string second = msg.substr(secondSpacePos + 1);
        int time = std::stoi(msg.substr(secondSpacePos + 1));

        journal entry;
        entry.takt = this->tact;
        entry.type = "Call";
        entry.number = first;
        entry.time_talk = time;
        get_sub_object(first)->journal_list.push_back(entry);
        entry.takt = this->tact;
        entry.type = "Bell";
        entry.number = first;
        entry.time_talk = time;
        get_sub_object(second)->journal_list.push_back(entry);
    }
}
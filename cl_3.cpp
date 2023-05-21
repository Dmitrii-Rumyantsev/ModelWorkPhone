#include "cl_3.h"
#include "cl_2.h"
#include "cl_5.h"

cl_3::cl_3(cl_base* head_object, string s_name) :cl_base(head_object, s_name) {
    this->set_sum_calls(0);
    this->set_count_talk(0);
    this->set_count_call(0);
    this->set_is_free(true);
	this->number = 3;
}
void cl_3::signal_3(string& msg) {
    // Обработка сигнала signal_3
}

void cl_3::handler_3(string msg) {
    string command = msg;
    if (command.substr(0, 12) == "Call request") {
        size_t firstSpacePos = msg.find(' ');
        size_t secondSpacePos = msg.find(' ', firstSpacePos + 1);

        // Извлекаем значения first, second и time из строки
        string first = msg.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
        string second = msg.substr(secondSpacePos + 1);

        if (stoi(second) < 999999 || stoi(second) > 10000000) {
            msg = "The subscriber's number was dialed incorrectly: " + second;
            emit_signal(SIGNAL_D(cl_3::signal_3), msg);
            return; // Прекратить дальнейшую обработку
        }

        cl_base* obj_1 = get_sub_object("pult")->find_object_from_root(first);
        cl_base* obj_2 = get_sub_object("pult")->find_object_from_root(second);

        if (obj_1->get_is_free()) {
            if (obj_2) {
                if (obj_2->get_is_free()) {
                    obj_1->set_is_free(false);
                    obj_1->set_sum_calls(get_sum_calls() + 1);
                    obj_1->set_count_talk(get_count_talk() + 1);
                    obj_1->set_count_call(get_count_call() + 1);
                    obj_2->set_is_free(true);
                    obj_2->set_sum_calls(get_sum_calls() + 1);
                    obj_2->set_count_talk(get_count_talk() + 1);
                    obj_2->set_count_call(get_count_call() + 1);
                    emit_signal(SIGNAL_D(cl_3::signal_3), msg);
                } else {
                    msg = "Subscriber " + second + " is busy";
                    emit_signal(SIGNAL_D(cl_3::signal_3), msg);
                }
            } else {
                msg = "Subscriber " + second + " not found";
                emit_signal(SIGNAL_D(cl_3::signal_3), msg);
            }
        } else {
            msg = "The phone is busy, a new call is not possible: " + first;
            emit_signal(SIGNAL_D(cl_3::signal_3), msg);
        }
    }
}


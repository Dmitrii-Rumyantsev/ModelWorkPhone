#ifndef __cl_base_H
#define __cl_base_H
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define SIGNAL_D(signal_f) (TYPE_SIGNAL) (&signal_f)
#define HANDLER_D(hendler_f) (TYPE_HANDLER) (&hendler_f)
class cl_base;
typedef void (cl_base::* TYPE_SIGNAL)(string& msg);
typedef void (cl_base::* TYPE_HANDLER)(string msg);
struct o_sh {
	TYPE_SIGNAL p_signal;
	cl_base* p_target;
	TYPE_HANDLER p_handler;
};

struct journal
{
	int takt = 0;
	string first_number;
	string second_number;
	int time_talk = 0;
};

class cl_base {
protected:
	static  cl_base* heads;
	string s_name;
	int state = 1;
	cl_base* p_head_object;
	vector <cl_base*> sub_objects;
	vector <o_sh*> connects;
	bool flag = true;
	vector<string> numbers;
	vector<journal*> journals_;
public:
	cl_base();
	cl_base* s_now;
	cl_base(cl_base* head_object, string s_name = "Base object");
	~cl_base();
	bool set_name(string new_name);
	string get_name();
	cl_base* get_head_object();
	cl_base* get_sub_object(string s_name);
	void print_tree();
	int count(string s_name);
	cl_base* search_object(string s_name);
	cl_base* find_object_from_root(string s_name);
	bool can_be_ready();
	int get_ready();
	void set_state(int state);
	void print_status();
	bool set_head_object(cl_base* now);
	bool delete_sub_object(string find_name);
	cl_base* find_object_from_current(string s_name);
	cl_base * search_object_from_path(string s_path);
	string get_absolute_way();
	//����������� ��_3
	cl_base* find_obj_by_coord(string s_coord);
	cl_base* get_root();
	//����������� ��_4
	void set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER
		p_handler);
	void delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER
		p_handler);
	void emit_signal(TYPE_SIGNAL p_signal, string& command);
	TYPE_SIGNAL get_signal(cl_base* object);
	TYPE_HANDLER get_handler(cl_base* object);
	int number = 1;
	void setFullReadiness();
	friend class cl_2;
	friend class cl_3;
	friend class cl_4;
	friend class cl_5;

};
#endif //UNTITLED9_CL_BASE_H
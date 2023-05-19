#include "cl_base.h"
#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
cl_base::cl_base(cl_base * head_object, string s_name) {
	this->s_name = s_name;
	this->p_head_object = head_object;
	if (p_head_object != nullptr) {
		this->p_head_object = p_head_object;
		p_head_object->sub_objects.push_back(this);
	}
	else
	{
		this->p_head_object = heads;
		heads->sub_objects.push_back(this);
	}
	number = 1;
}

cl_base::cl_base() {
	p_head_object = nullptr;
	//name="System is ready";
}

cl_base* cl_base::heads = new cl_base();

cl_base::~cl_base() {
	for (int i = 0; i < this->sub_objects.size(); i++) {
		delete sub_objects[i];
	}
}
bool cl_base::set_name(string s_new_name) {
	if (p_head_object != nullptr) {
		for (int i = 0; i < p_head_object->sub_objects.size(); i++) {
			if (p_head_object->sub_objects[i]->get_name() == get_name())
				return false;
		}
	}
	this->s_name = s_new_name;
	return true;
}
string cl_base::get_name() {
	return s_name;
}
bool cl_base::can_be_ready() {
	cl_base* root = this;
	while (root->p_head_object) {
		if (root->p_head_object->state) {
			root = root->p_head_object;
		}
		else {
			return false;
		}
	}
	return true;
}
cl_base* cl_base::get_head_object() {
	return this->p_head_object;
}
cl_base* cl_base::get_sub_object(string s_name) {
	for (int i = 0; i < sub_objects.size(); i++) {
		if (sub_objects[i]->get_name() == s_name)
			return this->sub_objects[i];
	}
	for(int i = 0; i < sub_objects.size();i++)
	{
		if (sub_objects[i]->get_sub_object(s_name)->get_name() == s_name)
			return sub_objects[i]->get_sub_object(s_name);
	}
	return this;
}
int cl_base::count(string s_name)
{
	int counter = 0;
	if (this->get_name() == s_name)
		counter++;
	for (auto p_sub_object : sub_objects)
		counter += p_sub_object->count(s_name);
	return counter;
}
cl_base* cl_base::find_object_from_current(string s_name) {
	if (this->count(s_name) != 1) {
		return nullptr;
	}
	return search_object(s_name);
}
cl_base* cl_base::search_object(string s_name)
{
	if (this->count(s_name) != 1)
		return nullptr;
	if (this->get_name() == s_name)
		return this;
	for (auto p_sub_object : sub_objects)
	{
		cl_base* p_found = p_sub_object->search_object(s_name);
		if (p_found != nullptr)
		{
			return p_found;
		}
	}
	return nullptr;
}
cl_base* cl_base::find_object_from_root(string name) {
	if (true) {
		if (name == s_name)
			return this;
		for (auto& el : sub_objects) {
			if (el->get_name() == s_name)
				return el;
			cl_base* ans = el->find_object_from_root(name);
			if (ans)
				return ans;
		}
	}
	else {
		for (auto& el : sub_objects) {
			if (el->get_name() == name) return el;
		}
	}
	return nullptr;
}
void cl_base::set_state(int state) {
	if (state == 0) {
		this->state = 0;
		for (int i = 0; i < sub_objects.size(); i++) {
			sub_objects[i]->set_state(0);
		}
		return;
	}
	if (this->p_head_object == nullptr || this->p_head_object->state != 0) {
		this->state = state;
	}
}
void cl_base::print_tree() {
	static int level = 0;
	for (int i = 0; i < level; i++) {
		cout << " ";
	}
	cout << s_name << endl;
	level++;
	for (auto sub_object : sub_objects) {
		sub_object->print_tree();
	}
	level--;
}
void cl_base::print_status() {
	static int level = 0;
	for (int i = 0; i < level; i++) {
		cout << " ";
	}
	if (state) {
		cout << s_name << " is ready" << endl;
	}
	else {
		cout << s_name << " is not ready" << endl;
	}
	level++;
	for (auto sub_object : sub_objects) {
		sub_object->print_status();
	}
	level--;
}
bool cl_base::delete_sub_object(string s_name) {
	if (this->get_name() == s_name)
		return false;
	for (int i = 0; i < this->sub_objects.size(); i++) {
		if (this->sub_objects[i]->get_name() == s_name) {
			delete this->sub_objects[i];
			this->sub_objects.erase(this->sub_objects.begin() + i);
			return true;
		}
	}
	return false;
}
//Факультатив КВ_3
// Метод поиска по деревеу .
// Метод поиска от текущего объекта /
cl_base* cl_base::get_root() {//Поиск для корневого объекта
	cl_base* p_root = this;
	while (p_root->get_head_object() != nullptr) {
		p_root = p_root->get_head_object();
	}
	return p_root;
}
cl_base* cl_base::find_obj_by_coord(string s_coord) {//Поиск объекта по координате
	string s_nam;
	int i_slash_2;
	cl_base* p_obj = nullptr;
	if (s_coord == "") {
		return nullptr;
	}
	if (s_coord == "/") {
		return this->get_root();
	}
	if (s_coord == ".") {
		return this;
	}
	if (s_coord[0] == '/' && s_coord[1] == '/') {
		s_nam = s_coord.substr(2);
		return this->find_object_from_root(s_nam);
	}
	if (s_coord[0] == '.') {
		s_nam = s_coord.substr(1);
		return this->find_object_from_current(s_nam);
	}
	i_slash_2 = s_coord.find("/", 1);
	if (s_coord[0] == '/') {
		if (i_slash_2 != -1) {
			s_nam = s_coord.substr(1, i_slash_2 - 1);
			p_obj = this->get_root()->get_sub_object(s_nam);
			if (p_obj != nullptr) {
				return p_obj->find_obj_by_coord(s_coord.substr(i_slash_2 +1));
			}
			else {
				return p_obj;
			}
		}
		else {
			s_nam = s_coord.substr(1);
			return this->get_root()->get_sub_object(s_nam);
		}
	}
	else {
		if (i_slash_2 != -1) {
			s_nam = s_coord.substr(0, i_slash_2);
			p_obj = this->get_sub_object(s_nam);
			if (p_obj != nullptr) {
				return p_obj->find_obj_by_coord(s_coord.substr(i_slash_2 +
					1));
			}
			else {
				return p_obj;
			}
		}
		else {
			s_nam = s_coord;
			return this->get_sub_object(s_nam);
		}
	}
}
//Факультатив КВ_4
void cl_base::set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER
	p_handler) {
	o_sh* p_value;
	for (int i = 0; i < connects.size(); i++) {
		if (connects[i]->p_signal == p_signal &&
			connects[i]->p_target == p_target &&
			connects[i]->p_handler == p_handler)
			return;
	}
	p_value = new o_sh();
	p_value->p_signal = p_signal;
	p_value->p_target = p_target;
	p_value->p_handler = p_handler;
	connects.push_back(p_value);
}
void cl_base::delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target,
	TYPE_HANDLER p_handler) {
	for (int i = 0; i < connects.size(); i++) {
		if (connects[i]->p_signal == p_signal && connects[i]->p_target ==
			p_target && connects[i]->p_handler == p_handler) {
			connects.erase(connects.begin() + i);
		}
	}
}
string cl_base::get_absolute_way() {
	vector<string> v;
	string way = "";
	cl_base* obj = this;
	while (obj->p_head_object) {
		v.push_back(obj->s_name);
		obj = obj->p_head_object;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		way = way + "/";
		way = way + v[i];
	}
	if (way.empty()) way = "/";
	return way;
}
void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& command) {
	
	if (this->state == 0)
		return;
	TYPE_HANDLER p_handler;
	cl_base* obj;
	//call signal method
	(this->*p_signal)(command);
	//iterate on every handler
	if (this->flag) {
		for (int i = 0; i < connects.size(); i++) {
			if (connects[i]->p_signal == p_signal) {
				p_handler = connects[i]->p_handler;
				obj = connects[i]->p_target;
				if (obj->state != 0) {
					//call handler method
					(obj->*p_handler)(command);
				}
			}
		}
	}
}
int cl_base::get_ready() {
	return state;
}
void cl_base::setFullReadiness() {
	this->set_state(1);
	for (auto sub : sub_objects) {
		sub->setFullReadiness();
	}
}
#include <stdlib.h>
#include <stdio.h>
#include "cl_application.h"
int main() {
	cl_application object(nullptr,"ss"); // создание объекта приложение
	object.build_tree_objects(); // конструирование системы,
	return object.exec_app(); // запуск системы
}
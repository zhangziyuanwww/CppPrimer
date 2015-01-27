#include "Message.h"
#include <iostream>

int main()
{
	Message m1("pezy");
	Message m2("moop");

	Folder f1("pezy's folder");
	Folder f2("moop's folder");

	m1.save(f1);
	m2.save(f2);

	swap(m1, m2);

	f1.print_debug();
	f2.print_debug();

	m1.print_debug();
	m2.print_debug();

	return 0;
}
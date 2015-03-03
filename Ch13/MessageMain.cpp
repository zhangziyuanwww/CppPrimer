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

	// try to switch following statements.
	//std::swap(m1, m2); // (1)
	//swap(m1, m2); // (2)
	//std::swap(f1, f2); // (3)
	swap(f1, f2); // (4)
	std::cout << "===============" << std::endl;
	
	//f1.print_debug();
	//f2.print_debug();

	//m1.print_debug();
	//m2.print_debug();

	Folder newFolder(std::move(Folder("mu's folder")));
	m1.save(newFolder);

	newFolder.print_debug();

	return 0;
}
#include "StrVec.h"
#include <iostream>

int main()
{
	StrVec vec;
	vec.reserve(6);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	
	vec.push_back("hello");
	vec.push_back("world");

	vec.resize(4);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "-EOF-" << std::endl;

	vec.resize(1);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "-EOF-" << std::endl;
}
#include "StrVec.h"
#include <iostream>

int main()
{
	StrVec vec;
	vec.push_back("hello");
	vec.push_back("world");

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
}
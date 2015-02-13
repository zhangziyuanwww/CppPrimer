#include "String.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

void foo(String x)
{
}

void bar(const String& x)
{
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(std::move(s0));
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	//svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(baz());
	svec.push_back("good job");

	for (const auto &s : svec) {
		std::cout << s.c_str() << std::endl;
	}
}
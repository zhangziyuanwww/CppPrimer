#include "StrBlob.h"
#include <iostream>

int main()
{
	StrBlob sb;
	sb.push_back("hello");
	sb.push_back("world");

	for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
		std::cout << iter.deref() << " ";
	}
	std::cout << std::endl;
}
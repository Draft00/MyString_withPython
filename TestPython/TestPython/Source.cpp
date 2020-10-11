
#include <iostream>
#include "hello.h"

int main()
{
	MyString s("1111");
	MyString s2("2");
	MyString s3;
	char a[] = "333";
	s3 = s + s2;
	std::cout << s3 << std::endl;
	s3 = s + a;
	std::cout << s3 << std::endl;
	s3.equall_c('c');
	std::cout << s3 << std::endl;
	s3 = s2;
	std::cout << s3 << std::endl;
}


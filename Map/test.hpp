#include <iostream>

template <class T1, class T2>
struct test
{
	T1 first;
	T2 second;

	test() : first(), second()
	{
		std::cout << "default" << std::endl;
	}

	template<class U, class V>
	test(const test<U,V>& pr) : test(pr.first, pr.second)
	{
	}

	test(const T1& a, const T2& b) : first(a), second(b)
	{
		std::cout << "fill" << std::endl;
	}
};
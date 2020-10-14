#include "list.hpp"
#include <list>

int main()
{

	std::cout << "\033[1;32mft::list\033[0m\n";
	{
		ft::list<std::string> list;
		ft::list<std::string>::iterator it;
		ft::list<std::string>::iterator ite;


		list.push_back("cc");
		list.push_back("yo");

		list.pop_front();
		list.pop_back();

		list.push_back("lol");

		it = list.begin();
		ite = list.end();

		std::cout << list.size() << std::endl;

		while (it != ite)
		{
			std::cout << *it++ << std::endl;
		}
	}
	std::cout << "\033[1;32mstd::list\033[0m\n";
	{
		std::list<std::string> list;
		std::list<std::string>::const_iterator it;
		std::list<std::string>::const_iterator ite;

		list.push_back("cc");
		list.push_back("yo");

		list.pop_front();
		list.pop_back();

		list.push_back("lol");

		it = list.begin();
		ite = list.end();

		std::cout << list.size() << std::endl;

		while (it != ite)
		{
			std::cout << *it++ << std::endl;
		}
	}
}
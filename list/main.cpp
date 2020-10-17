#include "list.hpp"
#include <list>

int main()
{

	std::cout << "\033[1;32m-- ft::list --\033[0m\n";
	{
		ft::list<std::string> list;
		ft::list<std::string>::iterator it;
		ft::list<std::string>::iterator ite;

        list.push_front("fuckers");
		list.push_back("fdp");
		list.push_back("cc");
		list.push_back("yo");
		list.push_back("tg");
//
//		list.pop_front();
//		list.pop_back();

        ite = list.end();
//        ite--;
//        ite--;
        it = list.begin();
//        it++;
//		it--;
//		it--;
//		it--;
//		it--;

//        std::cout << *list.erase(it, ite) << std::endl;
        list.resize(6, "PUTE");
        list.clear();

        it = list.begin();
        ite = list.end();

        std::cout << "\033[1;31msize:\033[0m\n" << list.size() << std::endl;
        std::cout << "\033[1;31mcontent:\033[0m\n";
        while (it != ite)
        {
            std::cout << *it++ << std::endl;
        }
		std::cout << std::endl;
	}
	std::cout << "\033[1;32m-- std::list --\033[0m\n";
	{
		std::list<std::string> list;
		std::list<std::string>::iterator it;
		std::list<std::string>::iterator ite;


        list.push_front("fuckers");
        list.push_back("fdp");
        list.push_back("cc");
        list.push_back("yo");
        list.push_back("tg");
//
//		list.pop_front();
//		list.pop_back();

        ite = list.end();
//        ite--;
//        ite--;
        it = list.begin();
//        it++;
//		it--;
//		it--;
//		it--;
//		it--;

//        std::cout << *list.erase(it, ite) << std::endl;

        list.resize(6, "PUTE");
        list.clear();

        it = list.begin();
        ite = list.end();

        std::cout << "\033[1;31msize:\033[0m\n" << list.size() << std::endl;
        std::cout << "\033[1;31mcontent:\033[0m\n";
        while (it != ite)
        {
            std::cout << *it++ << std::endl;
        }
		std::cout << std::endl;
	}
}
#include "List.hpp"
#include <list>

int main()
{

	std::cout << "\033[1;32m-- ft::list --\033[0m\n";
	{
		ft::list<int> list;
		ft::list<int>::iterator it;
		ft::list<int>::iterator ite;

		std::cout << "empty : " << list.empty() << std::endl;
		std::cout << "size : " << list.empty() << std::endl;

        list.push_front(42);
        list.push_back(99);
        list.push_back(53);
        list.push_back(66);
        list.push_back(12);
        list.push_back(33);
        list.push_back(150);

        std::cout << "empty : " << list.empty() << std::endl;
        std::cout << "size : " << list.empty() << std::endl;



        std::cout << "\033[1;31msize:\033[0m\n" << list.size() << std::endl;
        std::cout << "\033[1;31mcontent:\033[0m\n";
        it = list.begin();
        ite = list.end();
        while (it != ite)
        {
            std::cout << *it++ << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
	}
	std::cout << "\033[1;32m-- std::list --\033[0m\n";
	{
		std::list<int> list;
		std::list<int>::iterator it;
		std::list<int>::iterator ite;

        std::cout << "empty : " << list.empty() << std::endl;
        std::cout << "size : " << list.empty() << std::endl;

        list.push_front(42);
        list.push_back(99);
        list.push_back(53);
        list.push_back(66);
        list.push_back(12);
        list.push_back(33);
        list.push_back(150);

        std::cout << "empty : " << list.empty() << std::endl;
        std::cout << "size : " << list.empty() << std::endl;

        std::cout << "\033[1;31msize:\033[0m\n" << list.size() << std::endl;
        std::cout << "\033[1;31mcontent:\033[0m\n";
        it = list.begin();
        ite = list.end();
        while (it != ite)
        {
            std::cout << *it++ << std::endl;
        }
        std::cout << std::endl;
	}
}
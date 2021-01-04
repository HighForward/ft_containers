#include "List.hpp"
#include <list>

int main()
{

	std::cout << "\033[1;32m-- ft::list --\033[0m\n";
    {
        ft::list<int> list;
        ft::list<int> list2;


        list.push_front(15);
        list.push_front(15);
        list.push_front(15);
//        list.resize(0);

        for (ft::list<int>::iterator it = list.begin(); it != list.end(); it++)
        {
            std::cout << *it << std::endl;
        }


    }
	std::cout << "\033[1;32m-- std::list --\033[0m\n";
	{
        std::list<int> list;

        list.resize(0);


    }
}
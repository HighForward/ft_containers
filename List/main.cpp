#include "List.hpp"
#include <list>
#include "../ft_containers-tester/Tester.hpp"
//#include "../ft_containers-tester/Tester.hpp"
//#include "../Tests/list.hpp"
//#include "../ft_containers-tester/L"


int main()
{

	std::cout << "\033[1;32m-- ft::list --\033[0m\n";
    {
//        exec_test_list<ft::list<int> >();
        ft::list<int> list;
        ft::list<int> tsil;

        ft::list<int>::reverse_iterator rit;
        ft::list<int>::reverse_iterator rite;

        list = tsil;

//        list.push_back(15);
//        list.push_back(16);
//        list.push_back(17);


        rit = list.rbegin();
        rite = list.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            rit++;
        }

        ft::list<int>::const_reverse_iterator crit;
        rit = crit;

        crit = list.rbegin();

//        rit.operator*() = 15;




    }
	std::cout << "\033[1;32m-- std::list --\033[0m\n";
	{
        std::list<int> list;

        std::list<int>::reverse_iterator rit;
        std::list<int>::reverse_iterator rite;

//        list.push_back(15);
//        list.push_back(16);
//        list.push_back(17);
//

        rit = list.rbegin();
        rite = list.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            rit++;
        }



    }
}
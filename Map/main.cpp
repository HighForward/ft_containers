#include "Map.hpp"
#include "test.hpp"
#include <map>
#include <iostream>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{
		ft::map<int, int> map;

		ft::map<int, int>::iterator it;
		ft::map<int, int>::iterator ite;


        map[1] = 42;
        map[2] = 45;
        map[45] = 65;
        map[3] = 74;

        it = map.begin();
        it++;

        ite = map.end();

        map.erase(it, ite);
//		std::cout << map[0] << std::endl;



		map.print();
//        std::cout << "---------" << std::endl;
//		map.print();
//        map.clear();

	}
	std::cout << "--- std::map ---" << std::endl;
    {
        std::map<int, int> map;

//		ft::map<int, int>::iterator it;
//		ft::map<int, int>::const_iterator ite;

        map[0] = 42;
        map.erase(0);
        std::cout << map[0] << std::endl;

	}
}
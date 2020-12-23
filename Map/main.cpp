#include "Map.hpp"
#include "test.hpp"
#include <map>

#include <map>
#include <iostream>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{
        ft::map<int, int> map;

        map[0] = 42;
        map[1] = 35;

        ft::map<int, int>::iterator it;

        it = map.begin();

//        it->first = 5;


    }
	std::cout << "--- std::map ---" << std::endl;
    {
        std::map<int, int> map;

        map[0] = 42;
        map[1] = 35;

        std::map<int, int>::iterator it;

        it = map.begin();

//        it->first = 5;

	}
}
#include "MapRemake.hpp"
#include <map>
#include <iostream>
#include <cassert>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{

//        ft::map<int, int>::iterator it;
        ft::map<int, int> map;

        map.insert(std::pair<int, int>(15, 15));
        map.insert(std::pair<int, int>(13, 13));
        map.insert(std::pair<int, int>(2, 2));

        ft::map<int, int>::reverse_iterator it;
        ft::map<int, int>::reverse_iterator ite;


        it = map.rbegin();
        ite = map.rend();

        while (it != ite)
        {
            std::cout << it->first << " " << it->second << std::endl;
            it++;
        }
    }
	std::cout << "--- std::map ---" << std::endl;
    {
        std::map<int, int> map;

        map.insert(std::pair<int, int>(15, 15));
        map.insert(std::pair<int, int>(13, 13));
        map.insert(std::pair<int, int>(2, 2));

        std::map<int, int>::reverse_iterator it;
        std::map<int, int>::reverse_iterator ite;


        it = map.rbegin();
        ite = map.rend();

        while (it != ite)
        {
            std::cout << it->first << " " << it->second << std::endl;
            it++;
        }
	}
}
#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
    std::cout << "\033[1;32mft::vector\033[0m\n";
    {
        ft::vector<int> vec;
        ft::vector<int>::iterator it;
        ft::vector<int>::reverse_iterator rit;
        ft::vector<int>::reverse_iterator rite;

        vec.push_back(13);
//        vec.push_back(14);
//        vec.push_back(15);

        rit = vec.rbegin();
        rite = vec.rend();

//        ft::vector<int>::reverse_iterator rit = vec.rbegin();

//        ritc.operator[](0) = 15;
        std::cout << rit.operator[](0) << std::endl;


        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            rit++;
        }

    }
    std::cout << "\033[1;32mstd::vector\033[0m\n";
    {
        std::vector<int> vec;
        std::vector<int>::reverse_iterator rit;
        std::vector<int>::reverse_iterator rite;

//        vec.push_back(13);
//        vec.push_back(14);
//        vec.push_back(15);

        rit = vec.rbegin();
        rite = vec.rend();

        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            rit++;
        }

//        std::cout << *rit << std::endl;
//        std::cout << *rite << std::endl;
    }
}
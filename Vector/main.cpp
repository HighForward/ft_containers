#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
    std::cout << "\033[1;32mft::vector\033[0m\n";
    {
        ft::vector<int> vector;
        ft::vector<int>::iterator it;
        ft::vector<int>::iterator ite;

//        std::cout << (it - ite) << std::endl;
        vector.push_back(15);


    }
    std::cout << "\033[1;32mstd::vector\033[0m\n";
    {
        std::vector<int> vector;
        std::vector<int>::iterator it;
        std::vector<int>::iterator ite;


        vector.push_back(15);
//        vector.push_back(15);
//        vector.push_back(15);
//        vector.push_back(15);
//
//        it = vector.begin();
        std::cout << vector.front() << std::endl;

//        vector.at(3) = 12;



    }
}
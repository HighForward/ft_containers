#include "Queue.hpp"
#include <queue>
#include <list>

int main()
{
    {
        ft::queue<int> queue;
        ft::list<int> list;
        queue.push(42);
//
        queue.pop();
        std::cout << queue.empty() << std::endl;
        std::cout << "size : " << queue.empty() << std::endl;


        std::cout << "size : " << list.empty() << std::endl;
        std::cout << list.empty() << std::endl;
        queue.push(24);
        queue.push(24);
        std::cout << queue.empty() << std::endl;
        queue.push(99);
        queue.push(33);
        std::cout << queue.front() << std::endl;
        std::cout << queue.back() << std::endl;
        std::cout << queue.size() << std::endl;
//
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        std::cout << queue.back() << std::endl;
        std::cout << queue.back() << std::endl;
        std::cout << queue.front() << std::endl;
        std::cout << queue.front() << std::endl;
//    std::cout << queue.back() << std::endl;
//    std::cout << queue.front() << std::endl;
    }
    std::cout << "*-WALL-*" << std::endl;
    {
        std::queue<int> queue;
        std::list<int> list;
        queue.push(42);
//
        queue.pop();
        std::cout << queue.empty() << std::endl;
        std::cout << "size : " << queue.empty() << std::endl;


        std::cout << "size : " << list.empty() << std::endl;
        std::cout << list.empty() << std::endl;
        queue.push(24);
        queue.push(24);
        std::cout << queue.empty() << std::endl;
        queue.push(99);
        queue.push(33);
        std::cout << queue.front() << std::endl;
        std::cout << queue.back() << std::endl;
        std::cout << queue.size() << std::endl;
//
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        std::cout << queue.back() << std::endl;
        std::cout << queue.back() << std::endl;
        std::cout << queue.front() << std::endl;
        std::cout << queue.front() << std::endl;
    }

}
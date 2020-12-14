#include <iostream>
#include <type_traits>

//typename std::enable_if<std::is_integral<T>::value>::type* = nullptr

//template <class T, typename std::conditional<!std::is_const<T>::value>::type* = nullptr>
//void test(T t)
//{
//    std::cout << "doux jesus" << std::endl;
//}


template <class T, typename std::conditional<std::is_const<T>::value>::type = 0>
    void test(T t)
{
    std::cout << "dur jesus" << std::endl;
}

//template <class T, class = typename std::enable_if<std::is_const_v<T>

int main()
{
    int const i = 5;
    test(i);
}
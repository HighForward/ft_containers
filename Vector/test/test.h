#ifndef TEST_H
#define TEST_H

#include "../Vector.hpp"
#include <vector>

void 	print_info(ft::vector<int> &vec);
void 	print_info(std::vector<int> &vec);
void	print_vector(ft::vector<int>::iterator it, ft::vector<int>::iterator ite);
void	print_vector(std::vector<int>::iterator it, std::vector<int>::iterator ite);
void 	print_capacity(ft::vector<int>::iterator it, size_t capacity);
void 	print_capacity(std::vector<int>::iterator it, size_t capacity);

void ft_vector_insert();
void std_vector_insert();
void ft_vector_erase();
void std_vector_erase();
void ft_vector_clear();
void std_vector_clear();
void ft_vector_assign();
void std_vector_assign();
void ft_vector_push_pop();
void std_vector_push_pop();

#endif


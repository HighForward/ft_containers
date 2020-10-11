#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstdio>
#include <cmath>

namespace ft
{
	template<class T>
	class vectorIterator
	{
		private:
			T* c;

		public:
			vectorIterator(){};
			vectorIterator(T* current) { c = current; };
			vectorIterator<T> operator++()
			{
				c++;
				return (*this);
			}

			vectorIterator<T> operator++(int)
			{
				vectorIterator<T> temp = *this;
				c++;
				return (temp);
			}

			vectorIterator<T> operator--()
			{
				c--;
				return (*this);
			}

			vectorIterator<T> operator--(int)
			{
				vectorIterator<T> temp = *this;
				c--;
				return (temp);
			}

			bool operator!=(const vectorIterator &rhs)
			{
				if (c != rhs.c)
					return (true);
				return (false);
			}

			std::ptrdiff_t operator-(const vectorIterator &rhs)
			{
				return (this->c - rhs.c);
			}

			vectorIterator operator-(int n)
			{
				return (vectorIterator<T>(this->c - n));
			}

			vectorIterator operator+(int n)
			{
				return (vectorIterator<T>(this->c + n));
			}

			T &operator*()
			{
				return (*c);
			}
	};

	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef vectorIterator<T> iterator;
			typedef size_t size_type;

		private:
			value_type *_c;
			size_type _length;
			size_type _capacity;
			allocator_type allocator;

		public:

			//Iterator:
			iterator begin()
			{
				return (iterator(&at(0)));
			}

			iterator end()
			{
				return (iterator(&_c[_length]));
			}

			//TODO : const && reverse
//			iterator begin()
//			{
//				return (iterator(&at(0)));
//			}
//
//			iterator end()
//			{
//				return (iterator(&_c[_length]));
//			}

			//Capacity:
			size_type size() const
			{
				return (_length);
			}

			size_type max_size() const
			{
//				return ((2 ^ 64) / sizeof(value_type) - 1);
				return (0);
			}




			//return power of 2, new capacity
			size_type get_new_capacity(size_type requested_capacity)
			{
				size_type new_cap = 0;
				size_type power = 0;
				while (new_cap < requested_capacity)
					new_cap = pow(2, power++);
				return (new_cap);
			}

			//return current allocate memory size
			size_type capacity() const
			{
				return (_capacity);
			}
			
			//reserve memory if capacity < n
			void reserve(size_type n)
			{
					if (n > capacity())
					{
						T* new_c;
						new_c = allocator.allocate(n);
						for (size_type i = 0; i < _length; i++)
						{
							allocator.construct(&new_c[i], _c[i]);
							allocator.destroy(&_c[i]);
						}
						allocator.deallocate(_c, capacity());
						_capacity = n;
						_c = new_c;
					}
			}

			vector(const allocator_type& alloc = allocator_type())
			{
				allocator = alloc;
				_c = allocator.allocate(0);
				_capacity = 0;
				_length = 0;
			};

			vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type())
			{
				allocator = alloc;
				_capacity = n;
				_c = allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_c[i] = val;
				_length = n;
			};

			~vector()
			{
				allocator.deallocate(_c, capacity());
			}


			reference at(size_type n)
			{
				return (_c[n]);
			}

			const_reference at(size_type n) const
			{
				return (_c[n]);
			}

			reference front()
			{
				return (at(0));
			}

			bool empty() const
			{
				return (_length == 0);
			}

			void push_back(const value_type &val)
			{
				reserve(get_new_capacity(_length + 1));
				_c[_length++] = val;
			}

			iterator erase(iterator position)
			{
				std::ptrdiff_t index = position - begin();

				while (index < _length - 1)
				{
					_c[index] = _c[index + 1];
					index++;
				}
				_length--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				std::ptrdiff_t remove = last - first - 1;
				std::ptrdiff_t index = first - begin();

				for (size_type i = 0; i < remove; i++)
					_c[index + i] = _c[index + i + remove];
				_length -= remove;
				return (begin() + index);
			}

			void clear()
			{
				erase(begin(), end());
			}

			void assign(iterator first, iterator last)
			{
//				clear();
				last--;
				std::cout << *first << " " << *last  << std::endl;
//				_c = c_new;
			}


	};
}

#endif
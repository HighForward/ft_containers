#ifndef LIST_HPP
#define LIST_HPP

#include "ListIterator.hpp"
#include <iostream>
#include <cstddef>
#include <limits>
#include <algorithm>

namespace ft
{
	template<class T, class Alloc = std::allocator<NodeList<T> > >
	class list
	{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef T &reference;
            typedef const T *const_pointer;
            typedef const T &const_reference;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef listIterator<T> iterator;
            typedef constListIterator<T> const_iterator;
            typedef reverseListIterator<T> reverse_iterator;
			typedef constReverseListIterator<T> const_reverse_iterator;

		private:
			typedef struct	s_list
			{
				NodeList<T> *first;
				NodeList<T> *last;
				NodeList<T> *past_end;
			}				t_list;

			t_list _list;
			size_type _length;
            allocator_type _allocator;

            template<typename Type>
            void swap(Type &l, Type &r)
            {
                Type tmp(l);
                l = r;
                r = tmp;
            }

            NodeList<T>* node_at(size_type index)
            {
                iterator it = begin();
                for (size_type x = 0; x < index; x++)
                    it++;
                return (it._M_node);
            }

			void init()
			{
				_list.past_end = _allocator.allocate(1);
				_allocator.construct(_list.past_end, ft::NodeList<T>());
				_list.last = _list.past_end;
				_list.first = _list.past_end;
				init_past_end();
			}

			void init_past_end()
			{
				_list.past_end->next = _list.first;
				_list.past_end->prev = _list.last;
				_list.last->next = _list.past_end;
				_list.first->prev = _list.past_end;
			}

		public:

			list(const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = 0;
				init();
			}

			list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = 0;
                init();
				for (size_type x = n; x != 0; x--)
				    push_back(val);
			}

			list(iterator first, iterator last, const allocator_type &alloc = allocator_type())
            {
                _allocator = alloc;
                _length = 0;
                init();
                assign(first, last);
            }

            list (const list& x)
            {
                _allocator = x._allocator;
                _length = 0;
                init();
                assign(x.begin(), x.end());
            }

			~list()
			{
				NodeList<T> *remove;
				NodeList<T> *tmp;

				remove = _list.first;
				while (remove != end()._M_node)
				{
					tmp = remove->next;
                    _allocator.destroy(remove);
                    _allocator.deallocate(remove, 1);

                    remove = tmp;
				}
                _allocator.destroy(_list.past_end);
                _allocator.deallocate(_list.past_end, 1);
			}

			list<T>& operator=(const list<T>& rhs)
            {
                _length = 0;
                init();
			    assign(rhs.begin(), rhs.end());
			    return (*this);
            }

			//Iterator
			iterator begin()
			{
				return (iterator(_list.first));
			}

			iterator end()
			{
				if (_length == 0)
					return (iterator(_list.first));
				else
					return (iterator(_list.last->next));
			}

            const_iterator begin() const
            {
                return (iterator(_list.first));
            }

            const_iterator end() const
            {
                if (_length == 0)
                    return (iterator(_list.first));
                else
                    return (iterator(_list.last->next));
            }

            reverse_iterator rbegin()
            {
                if (_length == 0)
                    return (reverse_iterator(_list.first));
                else
                    return (reverse_iterator(_list.last));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(_list.first->prev));
            }

            const_reverse_iterator rbegin() const
            {
                if (_length == 0)
                    return (reverse_iterator(_list.first));
                else
                    return (reverse_iterator(_list.last));
            }

            const_reverse_iterator rend() const
            {
                return (reverse_iterator(_list.first->prev));
            }

			//Capacity
			bool empty() const
			{
				return (_length == 0);
			}

			size_type size() const
			{
				return (_length);
			}

			size_type max_size() const
			{
                return _allocator.max_size();
			}

			//Element access
			reference front()
			{
				return (_list.first->c);
			}

			const_reference front() const
			{
				return (_list.first->c);
			}

			reference back()
			{
				return (_list.last->c);
			}

			const_reference back() const
			{
				return (_list.last->c);
			}

			//Modifiers
            void assign(iterator first, iterator last)
            {
                list<T> tmp;

                tmp.insert(tmp.begin(), first, last);
                clear();
                insert(begin(), tmp.begin(), tmp.end());
            }

            void assign(size_type n, const value_type& val)
            {
                clear();
                for (size_type x = n; x > 0; x--)
                    push_back(val);
            }

			void push_back(const value_type &val)
			{
                NodeList<T> *node = _allocator.allocate(1);
                _allocator.construct(node, ft::NodeList<T>(val));

				node->next = _list.past_end;
				node->prev = _list.last;

				if (size() != 0)
					_list.last->next = node;
				else
					_list.first = node;
				_list.last = node;
				init_past_end();
				_length++;
			}

			void push_front(const value_type &val)
			{

                NodeList<T> *node = _allocator.allocate(1);
                _allocator.construct(node, ft::NodeList<T>(val));

				node->next = _list.first;
				node->prev = _list.past_end;

				if (size() != 0)
					_list.first->prev = node;
				else
					_list.last = node;
				_list.first = node;
				init_past_end();
				_length++;
			}

			void pop_back()
			{
				NodeList<T> *tmp = _list.last->prev;

                _allocator.destroy(_list.last);
                _allocator.deallocate(_list.last, 1);

				_list.last = tmp;
                init_past_end();

                _length--;
			}

			void pop_front()
			{
				NodeList<T> *tmp = _list.first->next;

                _allocator.destroy(_list.first);
                _allocator.deallocate(_list.first, 1);

				_list.first = tmp;
                init_past_end();
                _length--;
			}

			iterator insert(iterator position, const value_type& val)
			{
				if (position == begin())
				{
					push_front(val);
					return (begin());
				}
				else if (position == end())
				{
					push_back(val);
					return (end());
				}
				else
				{
                    NodeList<T> *node = _allocator.allocate(1);
                    _allocator.construct(node, ft::NodeList<T>(val));
					node->prev = position._M_node->prev;
					node->next = position._M_node;
					position._M_node->prev->next = node;
					position._M_node->prev = node;
					_length++;
					return (iterator(node));
				}
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				iterator tmp = position;
				for (size_type x = 0; x < n; x++)
					insert(tmp, val);
			}

			void insert(iterator position, iterator first, iterator last)
			{
                for (iterator it = first; it != last; it++)
                    insert(position, *it);
			}

			iterator erase(iterator position)
			{
				if (position == begin())
				{
                    pop_front();
                    return (begin());
                }
				else if (position == --end())
				{
                    pop_back();
                    return (end());
                }
				else if (position == end())
                    return (position);
				else
				{
                    NodeList<T> *tmp = position._M_node->prev;
                    tmp->next = position._M_node->next;
					position._M_node->next->prev = tmp;

                    _allocator.destroy(position._M_node);
                    _allocator.deallocate(position._M_node, 1);

					_length--;
					return (iterator(tmp->next));
				}
			}

			iterator erase(iterator first, iterator last)
            {
			    while  (first != last)
			        erase(first++);
			    return (last);
            }

            void swap (list<T> &x)
            {
                swap(_list, x._list);
                swap(this->_length, x._length);
                swap(this->_allocator, x._allocator);
            }

            void resize(size_type n, value_type val = value_type())
            {
			        for (size_type x = _length; x > n; x--)
                        pop_back();
			        for (size_type x = _length; x < n; x++)
			            push_back(val);
            }

            void clear()
            {
			    erase(begin(), end());
            }

            //Operations
            void splice (iterator position, list& x)
            {
                insert(position, x.begin(), x.end());
                x.clear();
            }

            void splice (iterator position, list& x, iterator i)
            {
                insert(position, *i);
                x.erase(i);
            }

            void splice (iterator position, list& x, iterator first, iterator last)
            {
                insert(position, first, last);
                x.erase(first, last);
            }

            void remove(const value_type& val)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (*it == val)
                        erase(it);
                }
            }

            template <class Predicate>
            void remove_if(Predicate pred)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (pred(*it))
                        erase(it);
                }
            }

            void merge (list& x)
            {
                if (&x == this)
                    return ;
                insert(this->begin(), x.begin(), x.end());
                sort();
                x.clear();
            }

            template<class Compare>
            void merge (list& x, Compare comp)
            {
                if (&x == this)
                    return ;
                insert(this->begin(), x.begin(), x.end());
                sort(comp);
                x.clear();
            }

            void unique()
            {
                if (this->empty())
                    return;
                iterator begin = this->begin();
                while (begin != this->end())
                {
                    iterator current = begin;
                    current++;
                    while (current != this->end())
                    {
                        if (*current == *begin)
                            this->erase(current);
                        current++;
                    }
                    begin++;
                }
            }

            template <class BinaryPredicate>
            void unique(BinaryPredicate binary_pred)
            {
                if (this->empty())
                    return;
                iterator begin = this->begin();
                while (begin != this->end())
                {
                    iterator current = begin;
                    current++;
                    while (current != this->end())
                    {
                        if (binary_pred(*begin, *current))
                            this->erase(current);
                        current++;
                    }
                    begin++;
                }
            }

            void sort()
            {
                NodeList<T> tmp;
                iterator x = begin();
                x++;
                if (size() < 2)
                    return ;
                while (x != end())
                {
                    iterator y(x._M_node->prev);
                    if (*x < *y)
                    {
                        swap(*x, *y);
                        x = begin();
                    }
                    x++;
                }
            }

            template<class Compare>
            void sort(Compare comp)
            {
                NodeList<T> tmp;
                iterator x = begin();
                x++;
                if (size() < 2)
                    return ;
                while (x != end())
                {
                    iterator y(x._M_node->prev);
                    if (comp(*x, *y))
                    {
                        swap(*x, *y);
                        x = begin();
                    }
                    x++;
                }
            }

            void reverse()
            {
                if (size() < 2)
                    return ;
                for (size_type x = 0; x < (size() / 2); x++)
                {
                    value_type tmp = node_at(_length - x - 1)->c;
                    node_at(_length - x - 1)->c = node_at(x)->c;
                    node_at(x)->c = tmp;
                }
            }

            allocator_type get_allocator() const
            {
                return (_allocator);
            }
	};

    template<class T>
    bool operator==(list<T> &lhs, list<T> &rhs)
    {
        typename list<T>::iterator begin_lhs = lhs.begin();
        typename list<T>::iterator begin_rhs = rhs.begin();
        if (lhs.size() != rhs.size())
            return (false);
        while (begin_lhs != lhs.end() && begin_rhs != rhs.end())
        {
            if (*begin_lhs++ != *begin_rhs++)
                return (false);
        }
        return (true);
    }

    template<class T>
    bool operator!=(list<T> &lhs, list<T> &rhs)
    {
        return (!(lhs == rhs));
    }

    template<class T>
    bool operator<(list<T> &lhs, list<T> &rhs)
    {
        if (lhs == rhs)
            return (false);
        if (lhs.size() != rhs.size()) {
            return (lhs.size() < rhs.size());
        }
        typename list<T>::iterator begin_lhs = lhs.begin();
        typename list<T>::iterator begin_rhs = rhs.begin();
        while (begin_lhs != lhs.end() && begin_rhs != rhs.end())
        {
            if (*begin_lhs != *begin_rhs)
                return (*begin_lhs < *begin_rhs);
            begin_lhs++;
            begin_rhs++;
        }
        return (false);
    }

    template<class T>
    bool operator<=(list<T> &lhs, list<T> &rhs)
    {
        return ((lhs < rhs) || (lhs == rhs));
    }

    template<class T>
    bool operator>(list<T> &lhs, list<T> &rhs)
    {
        return (!(lhs <= rhs));
    }

    template<class T>
    bool operator>=(list<T> &lhs, list<T> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }
}



#endif
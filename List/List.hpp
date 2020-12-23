#ifndef LIST_HPP
#define LIST_HPP


#include <iostream>
#include <cstddef>
#include <algorithm>

namespace ft
{
	template<typename T>
	class NodeList
	{
		public:
			T c;
			NodeList *prev;
			NodeList *next;

			NodeList()
			{
			    c = T();
			}
			NodeList(const T &content) : c(content), next(NULL), prev(NULL) {}
			bool operator<(NodeList &rhs)
            {
			    return (c < rhs.c);
            }
	};

    template<typename T>
    class constListIterator;

	template<typename T>
	class listIterator
	{
        public:
			NodeList<T>* _M_node;

			listIterator() {}
			listIterator(NodeList<T> *current) : _M_node(current) {}
			listIterator(listIterator const *copy) : _M_node(copy->_M_node) {}
			~listIterator() {}

            operator constListIterator<T>() { return (constListIterator<T>(_M_node)); }
            listIterator<T>(const constListIterator<T> &x) { this->_M_node = x._M_node; }
            listIterator<T>& operator=(const constListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }

            listIterator& operator=(const listIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            listIterator& operator++() { _M_node = _M_node->next; return (*this); }
			listIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next; return (listIterator<T>(temp)); }
			listIterator& operator--() { _M_node = _M_node->prev; return (*this); }
			listIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (listIterator<T>(temp)); }

			bool operator==(listIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
			bool operator!=(listIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
			T* operator->() { return (_M_node); }
            T& operator*() { return (_M_node->c); }
	};

    template<typename T>
    class constListIterator
    {
        public:
            NodeList<T>* _M_node;

            constListIterator() {}
            constListIterator(NodeList<T> *current) : _M_node(current) {}
            constListIterator(constListIterator const *copy) : _M_node(copy->_M_node) {}
            ~constListIterator() {}

            operator listIterator<T>() { return (listIterator<T>(_M_node)); }
            constListIterator<T>(const listIterator<T> &x) { this->_M_node = x._M_node; }
            constListIterator<T>& operator=(const listIterator<T>& x) { this->_M_node = x._M_node; return (*this); }

            constListIterator& operator=(const constListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            constListIterator& operator++() { _M_node = _M_node->next; return (*this); }
            constListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next; return (constListIterator<T>(temp)); }
            constListIterator& operator--() { _M_node = _M_node->prev; return (*this); }
            constListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (constListIterator<T>(temp)); }

            bool operator==(constListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(constListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            const T* operator->() { return (_M_node); }
            const T& operator*() { return (_M_node->c); }
    };


    template<typename T>
    class constReverseListIterator;
    
    template<typename T>
    class reverseListIterator
    {
        public:
            NodeList<T>* _M_node;

            reverseListIterator() {}
            reverseListIterator(NodeList<T> *current) : _M_node(current) {}
            reverseListIterator(reverseListIterator const *copy) : _M_node(copy->_M_node) {}
            ~reverseListIterator() {}

            operator constReverseListIterator<T>() { return (constReverseListIterator<T>(_M_node)); }
            reverseListIterator<T>(const constReverseListIterator<T> &x) { this->_M_node = x._M_node; }
            reverseListIterator<T>& operator=(const constReverseListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }

            reverseListIterator& operator=(const reverseListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            reverseListIterator& operator++() { _M_node = _M_node->prev; return (*this); }
            reverseListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (reverseListIterator<T>(temp)); }
            reverseListIterator& operator--() { _M_node = _M_node->next; return (*this); }
            reverseListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next ; return (reverseListIterator<T>(temp)); }

            bool operator==(reverseListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(reverseListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            T* operator->() { return (_M_node); }
            T& operator*() { return (_M_node->c); }
    };

    
    template<typename T>
    class constReverseListIterator
    {
        public:
            NodeList<T>* _M_node;

            constReverseListIterator() {}
            constReverseListIterator(NodeList<T> *current) : _M_node(current) {}
            constReverseListIterator(constReverseListIterator const *copy) : _M_node(copy->_M_node) {}
            ~constReverseListIterator() {}

            operator reverseListIterator<T>() { return (reverseListIterator<T>(_M_node)); }
            constReverseListIterator<T>(const reverseListIterator<T> &x) { this->_M_node = x._M_node; }
            constReverseListIterator<T>& operator=(const reverseListIterator<T>& x) { this->_M_node = x._M_node; return (*this); }


            constReverseListIterator& operator=(const constReverseListIterator<T> &rhs) { _M_node = rhs._M_node; return (*this); }

            constReverseListIterator& operator++() { _M_node = _M_node->prev; return (*this); }
            constReverseListIterator operator++(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->prev; return (constReverseListIterator<T>(temp)); }
            constReverseListIterator& operator--() { _M_node = _M_node->next; return (*this); }
            constReverseListIterator operator--(int) { NodeList<T>* temp = _M_node; _M_node = _M_node->next ; return (constReverseListIterator<T>(temp)); }

            bool operator==(constReverseListIterator<T> const &rhs) { return (this->_M_node == rhs._M_node); }
            bool operator!=(constReverseListIterator<T> const &rhs) { return (this->_M_node != rhs._M_node); }
            const T* operator->() { return (_M_node); }
            const T& operator*() { return (_M_node->c); }
    };
    
    
    
    
	template<class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef T &reference;

			typedef const T &const_reference;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;

			typedef listIterator<T> iterator;
			typedef constListIterator<T> const_iterator;
			typedef reverseListIterator<T> reverse_iterator;
			typedef constReverseListIterator<T> const_reverse_iterator;

			typedef size_t size_type;

		private:
			typedef struct	s_list
			{
				NodeList<T> *first;
				NodeList<T> *last;
				NodeList<T> *past_end;
			}				t_list;

			t_list _list;
			allocator_type _allocator;
			size_type _length;

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
				_list.past_end = new NodeList<T>;
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

			~list()
			{
				NodeList<T> *remove;
				NodeList<T> *tmp;

				remove = _list.first;
				while (remove != end()._M_node)
				{
					tmp = remove->next;
					delete remove;
					remove = tmp;
				}
				delete _list.past_end;
			}

			//operator=
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
				//to_do;
				return (0);
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
				NodeList<T> *node = new NodeList<T>(val);
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
				NodeList<T> *node = new NodeList<T>(val);
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
				delete _list.last;
				_list.last = tmp;
                init_past_end();

                _length--;
			}

			void pop_front()
			{
				NodeList<T> *tmp = _list.first->next;
				delete _list.first;
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
					NodeList<T> *node = new NodeList<T>(val);
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
					delete position._M_node;
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
	};

    template<class T>
    bool operator==(list<T> &lhs, list<T> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename list<T>::iterator begin_lhs = lhs.begin();
        typename list<T>::iterator begin_rhs = rhs.begin();
        while (begin_lhs != lhs.end() && begin_rhs != rhs.end())
        {
            if (*begin_lhs != *begin_rhs)
                return (false);
            begin_lhs++;
            begin_rhs++;
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
}



#endif